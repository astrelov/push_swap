/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_ps_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:43:04 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 15:44:48 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			input_is_valid(char **av)
{
	int		*nbrs;
	char	*nbr;
	int		i;
	int		equal;

	nbrs = get_nbrs(av);
	i = -1;
	while (++i < g_total_nbrs_amnt)
	{
		nbr = ft_itoa(nbrs[i]);
		equal = ft_strequ(nbr, *(av + i + 1));
		ft_memdel((void **)&nbr);
		if (!equal)
			return (INVALID);
	}
	ft_d_bblsort(nbrs, (size_t)g_total_nbrs_amnt);
	while (--i > 0)
		if (nbrs[i - 1] == nbrs[i])
		{
			ft_memdel((void **)&nbrs);
			return (INVALID);
		}
	ft_memdel((void **)&nbrs);
	return (VALID);
}

int			*get_nbrs(char **av)
{
	int		*nbrs;
	int		i;

	nbrs = (int *)ft_memalloc(g_total_nbrs_amnt * sizeof(int));
	i = 0;
	while (i < g_total_nbrs_amnt)
		nbrs[i++] = ft_atoi(*(++av));
	return (nbrs);
}

void		error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}
