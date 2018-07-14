/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_is_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:42:37 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 14:46:14 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int		lst_is_sorted(t_stack *stack)
{
	t_node	*node;

	if (!stack || stack->nodes_amount != g_total_nbrs_amnt)
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
