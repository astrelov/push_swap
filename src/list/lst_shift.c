/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:43:01 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 19:56:29 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*lst_shift(t_stack *stack)
{
	t_node	*head;

	if (!stack || !HEAD)
		return (NULL);
	stack->nodes_amount -= 1;
	head = HEAD;
	if (stack->nodes_amount == 0)
		HEAD = NULL;
	else
	{
		HEAD->next->prev = HEAD->prev;
		HEAD->prev->next = HEAD->next;
		HEAD = HEAD->next;
	}
	head->next = NULL;
	head->prev = NULL;
	return (head);
}
