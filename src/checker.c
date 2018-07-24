/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:40:33 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/19 12:44:42 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_instruction(t_stack *a, t_stack *b, char *op)
{
	if (ft_strequ(op, "sa"))
		sa(a);
	else if (ft_strequ(op, "sb"))
		sb(b);
	else if (ft_strequ(op, "ss"))
		ss(a, b);
	else if (ft_strequ(op, "pa"))
		pa(a, b);
	else if (ft_strequ(op, "pb"))
		pb(a, b);
	else if (ft_strequ(op, "ra"))
		ra(a);
	else if (ft_strequ(op, "rb"))
		rb(b);
	else if (ft_strequ(op, "rra"))
		rra(a);
	else if (ft_strequ(op, "rrb"))
		rrb(b);
	else if (ft_strequ(op, "rr"))
		rr(a, b);
	else if (ft_strequ(op, "rrr"))
		rrr(a, b);
	else
		error();
}

void	read_instructions(t_stack *a, t_stack *b)
{
	char	*op;

	while (ft_gnl(0, &op))
	{
		do_instruction(a, b, op);
		ft_strdel(&op);
	}
	ft_strdel(&op);
}

int		check(char **nbrs, int nbrs_amount)
{
	int		*nbrs_arr;
	int 	sorted;
	t_stack	a;
	t_stack	b;

	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	nbrs_arr = get_nbrs(nbrs, nbrs_amount);
	lst_create(&a, nbrs_arr, nbrs_amount);
	read_instructions(&a, &b);
	ft_memdel((void **)&nbrs_arr);
	sorted = lst_is_sorted(&a, nbrs_amount);
	free_stack_nodes(&a);
	free_stack_nodes(&b);
	return (sorted);
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
	if (check(nbrs, nbrs_amount))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}
