/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:41:42 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/17 10:02:50 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sa(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->nodes_amount < 2)
		return ;
	node = lst_shift(stack);
	HEAD = HEAD->next;
	lst_push_head(stack, node);
	HEAD = HEAD->prev;
}

void	sb(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->nodes_amount < 2)
		return ;
	node = lst_shift(stack);
	HEAD = HEAD->next;
	lst_push_head(stack, node);
	HEAD = HEAD->prev;
}
