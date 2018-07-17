/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_is_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:42:37 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 19:56:30 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		lst_is_sorted(t_stack *stack, int all_nbrs_amount)
{
	t_node	*node;

	if (stack->nodes_amount != all_nbrs_amount)
		return (UNSORTED);
	node = HEAD;
	while (node->next != HEAD)
	{
		if (node->nbr > node->next->nbr)
			return (UNSORTED);
		node = node->next;
	}
	return (SORTED);
}
