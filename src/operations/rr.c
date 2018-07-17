/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:41:39 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/15 11:08:23 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack *stack)
{
	if (!stack->nodes_amount)
		return ;
	HEAD = HEAD->prev;
}

void	rrb(t_stack *stack)
{
	if (!stack->nodes_amount)
		return ;
	HEAD = HEAD->prev;
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
