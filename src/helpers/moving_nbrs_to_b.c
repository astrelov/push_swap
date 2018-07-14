/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_nbrs_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:39:46 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 15:41:52 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		prepare_a_to_pb(t_stack *stack, t_nbrs_to_move *nbrs,
							t_min_nbr *to_move)
{
	t_min_nbr	*node;

	if (to_move->index < stack->nodes_amount / 2 + 1)
		while (to_move->index--)
		{
			ra(stack);
			node = nbrs->nbrs_positions;
			while (node)
			{
				if (node != to_move)
					node->index = node->index ? node->index - 1 : stack->nodes_amount - 1;
				node = node->next;
			}
		}
	else
		while (stack->nodes_amount - to_move->index++)
		{
			rra(stack);
			node = nbrs->nbrs_positions;
			while (node)
			{
				if (node != to_move)
					node->index = node->index == stack->nodes_amount - 1 ? 0 : node->index + 1;
				node = node->next;
			}
		}
}

void			move_nbrs_to_b(t_stack *a, t_stack *b, t_nbrs_to_move *nbrs)
{
	t_min_nbr		*closest;

	while (a->nodes_amount > 3)
	{
		nbrs->max_amount = a->nodes_amount / 4;
		nbrs->curr_amount = 0;
		while (a->nodes_amount - nbrs->curr_amount > 3 && nbrs->curr_amount < nbrs->max_amount)
			find_next_min(a, nbrs);
		while (nbrs->curr_amount)
		{
			closest = find_closest(a, nbrs);
			prepare_a_to_pb(a, nbrs, closest);
			pb(a, b);
			free_node(a, nbrs, closest);
		}
	}
}
