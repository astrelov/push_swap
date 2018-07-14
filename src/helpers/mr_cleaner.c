/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mr_cleaner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 17:30:29 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 17:30:29 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void		remove_node_from_nbrs_to_move_list(t_stack *stack,
									t_nbrs_to_move *nbrs, t_min_nbr *to_free)
{
	t_min_nbr	*node;

	if (to_free == nbrs->nbrs_positions)
		nbrs->nbrs_positions = to_free->next;
	else
	{
		node = nbrs->nbrs_positions;
		while (node)
		{
			if (node->next == to_free)
			{
				node->next = node->next->next;
				break ;
			}
			node = node->next;
		}
	}
	ft_memdel((void **)&to_free);
	nbrs->curr_amount--;
	node = nbrs->nbrs_positions;
	while (node)
	{
		node->index = node->index ? node->index - 1 : stack->nodes_amount - 1;
		node = node->next;
	}
}
