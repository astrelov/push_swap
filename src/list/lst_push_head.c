/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_head.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:42:58 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 14:45:33 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	lst_push_head(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	stack->nodes_amount += 1;
	if (!HEAD)
	{
		node->next = node;
		node->prev = node;
		HEAD = node;
		return ;
	}
	node->next = HEAD;
	node->prev = HEAD->prev;
	HEAD->prev->next = node;
	HEAD->prev = node;
	HEAD = node;
}
