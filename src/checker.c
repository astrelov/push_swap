/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:40:33 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/16 13:01:54 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_instruction(t_stack *a, t_stack *b, char *op)
{
	if (ft_strequ(op, "sa"))
		sa(a);
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
	int 	fd = open("./output.txt", O_RDONLY);

	while (ft_gnl(fd, &op))
	{
		do_instruction(a, b, op);
		free(op);
	}
	free(op);
}

int		main(int ac, char **av)
{
	int		*nbrs_arr;
	t_stack	a;
	t_stack	b;

	if (!input_is_valid(av, ac - 1))
		error();
	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	nbrs_arr = get_nbrs(av, ac - 1);
	lst_create(&a, nbrs_arr, ac - 1);
	read_instructions(&a, &b);
	ft_memdel((void **)&nbrs_arr);
	if (lst_is_sorted(&a, ac - 1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
