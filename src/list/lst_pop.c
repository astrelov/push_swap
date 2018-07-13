/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:42:48 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 14:45:25 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*lst_pop(t_stack *stack)
{
	t_node	*bot;

	if (!stack || !HEAD)
		return (NULL);
	stack->nodes_amount -= 1;
	bot = HEAD->prev;
	if (stack->nodes_amount == 0)
	{
		HEAD = NULL;
		return (bot);
	}
	HEAD->prev = bot->prev;
	HEAD->prev->next = HEAD;
	bot->prev = NULL;
	bot->next = NULL;
	return (bot);
}
