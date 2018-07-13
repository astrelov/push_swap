/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_splice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: null <null@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 18:04:01 by null              #+#    #+#             */
/*   Updated: 2018/07/14 14:45:41 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*lst_splice(t_stack *stack, t_node *node)
{
	if (!stack || !HEAD || !node)
		return (NULL);
	stack->nodes_amount -= 1;
	if (stack->nodes_amount == 0)
		HEAD = NULL;
	else
	{
		node->next->prev = node->prev;
		node->prev->next = node->next;
	}
	if (node == HEAD)
		HEAD = node->next;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
