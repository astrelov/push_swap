/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:41:33 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 19:56:31 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *stack)
{
	if (!stack->nodes_amount)
		return ;
	HEAD = HEAD->next;
}

void	rb(t_stack *stack)
{
	if (!stack->nodes_amount)
		return ;
	HEAD = HEAD->next;
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
