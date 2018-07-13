/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:41:28 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 14:45:44 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		pa(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!g_checker)
		write(1, "pa\n", 3);
	if (!a || !b || !b->nodes_amount)
		return;
	node = lst_shift(b);
	lst_push_head(a, node);
}

void		pb(t_stack *a, t_stack *b)
{
	t_node	*node;

	if (!g_checker)
		write(1, "pb\n", 3);
	if (!a || !b || !a->nodes_amount)
		return;
	node = lst_shift(a);
	lst_push_head(b, node);
}
