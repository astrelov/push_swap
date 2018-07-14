/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:41:14 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 16:29:30 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	case_three_nbrs(t_stack *stack)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = HEAD->nbr;
	n2 = HEAD->next->nbr;
	n3 = HEAD->next->next->nbr;
	if (n1 > n2 && n2 > n3)
	{
		sa(stack);
		rra(stack);
	}
	else if (n1 > n3 && n3 > n2)
		ra(stack);
	else if (n2 > n1 && n1 > n3)
		rra(stack);
	else if (n2 > n3 && n3 > n1)
	{
		sa(stack);
		ra(stack);
	}
	else if (n3 > n1 && n1 > n2)
		sa(stack);
}

void	sort(t_stack *a, t_stack *b)
{
	t_nbrs_to_move	*nbrs;

	nbrs = (t_nbrs_to_move *)ft_memalloc(sizeof(t_nbrs_to_move));
	move_nbrs_to_b(a, b, nbrs);
	case_three_nbrs(a);
	move_nbrs_to_a(a, b, nbrs);
	fix_a_stack_head(a);
	ft_memdel((void **)&nbrs);
}

void	push_swap(char **av)
{
	int		*nbrs_arr;
	t_stack	a;
	t_stack	b;

	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	nbrs_arr = get_nbrs(av);
	lst_create(&a, nbrs_arr);
	ft_memdel((void **)&nbrs_arr);
	if (!lst_is_sorted(&a))
		sort(&a, &b);
}

int		main(int ac, char **av)
{
	g_total_nbrs_amnt = (size_t)ac - 1;
	if (g_total_nbrs_amnt < 2)
		return (0);
	if (!input_is_valid(av))
		error();
	push_swap(av);
	return (0);
}
