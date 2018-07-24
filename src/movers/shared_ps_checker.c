/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_ps_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:43:04 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/24 20:57:23 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			check_for_duplicates(int *nbrs, int nbrs_amount)
{
	ft_d_bblsort(nbrs, (size_t)nbrs_amount);
	while (--nbrs_amount > 0)
		if (nbrs[nbrs_amount - 1] == nbrs[nbrs_amount])
			return (INVALID);
	return (VALID);
}

int			input_is_valid(char **av, int nbrs_amount)
{
	int		*nbrs;
	char	*nbr;
	int		i;
	int		equal;

	nbrs = get_nbrs(av, nbrs_amount);
	i = -1;
	while (++i < nbrs_amount)
	{
		nbr = ft_itoa(nbrs[i]);
		equal = ft_strequ(nbr, *(av + i));
		ft_memdel((void **)&nbr);
		if (!equal)
		{
			ft_memdel((void **)&nbrs);
			return (INVALID);
		}
	}
	i = check_for_duplicates(nbrs, nbrs_amount);
	ft_memdel((void **)&nbrs);
	return (i);
}

int			*get_nbrs(char **av, int nbrs_amount)
{
	int		*nbrs;
	int		i;

	nbrs = (int *)ft_memalloc(nbrs_amount * sizeof(int));
	i = 0;
	while (i < nbrs_amount)
		nbrs[i++] = ft_atoi(*(av++));
	return (nbrs);
}

void		error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

int 		count_nbrs(char **nbrs)
{
	int		amount;

	amount = 0;
	while (*nbrs++)
		amount++;
	return (amount);
}
