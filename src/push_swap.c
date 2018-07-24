/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:41:14 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/17 10:42:40 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort(t_stack *a, t_stack *b, int nbrs_amount)
{
	t_nbrs_to_move	*nbrs;

	nbrs = (t_nbrs_to_move *)ft_memalloc(sizeof(t_nbrs_to_move));
	move_nbrs_to_b(a, b, nbrs);
	case_three_nbrs(a);
	move_nbrs_to_a(a, b, nbrs, nbrs_amount);
	fix_a_stack_head(a);
	ft_memdel((void **)&nbrs);
}

void	push_swap(char **av, int nbrs_amount)
{
	int		*nbrs_arr;
	t_stack	a;
	t_stack	b;

	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	nbrs_arr = get_nbrs(av, nbrs_amount);
	lst_create(&a, nbrs_arr, nbrs_amount);
	ft_memdel((void **)&nbrs_arr);
	if (!lst_is_sorted(&a, nbrs_amount))
		sort(&a, &b, nbrs_amount);
	free_stack_nodes(&a);
	free_stack_nodes(&b);
}

int		main(int ac, char **av)
{
	char	**nbrs;
	int 	nbrs_amount;

	if (ac == 1)
		return (0);
	nbrs = av + 1;
	nbrs_amount = ac - 1;
	if (ac == 2)
	{
		if (!(nbrs = ft_strsplit(*(av + 1), ' ')))
			error();
		nbrs_amount = count_nbrs(nbrs);
	}
	if (!input_is_valid(nbrs, nbrs_amount))
		error();
	push_swap(nbrs, nbrs_amount);
	return (0);
}
