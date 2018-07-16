/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_nbrs_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:39:46 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 20:36:24 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		rotate_a_forward(t_stack *stack, t_nbrs_to_move *nbrs,
									t_min_nbr *to_move)
{
	t_min_nbr	*node;

	while (to_move->index--)
	{
		op_handler(stack, NULL, "ra");
		node = nbrs->nbrs_positions;
		while (node)
		{
			if (node != to_move)
				NIND = NIND ? NIND - 1 : stack->nodes_amount - 1;
			node = node->next;
		}
	}
}

static void		rotate_a_backward(t_stack *stack, t_nbrs_to_move *nbrs,
									t_min_nbr *to_move)
{
	t_min_nbr	*node;

	while (stack->nodes_amount - to_move->index++)
	{
		op_handler(stack, NULL, "rra");
		node = nbrs->nbrs_positions;
		while (node)
		{
			if (node != to_move)
				NIND = NIND == stack->nodes_amount - 1 ? 0 : NIND + 1;
			node = node->next;
		}
	}
}

static void		prepare_a_to_pb(t_stack *stack, t_nbrs_to_move *nbrs,
							t_min_nbr *to_move)
{
	if (to_move->index < stack->nodes_amount / 2 + 1)
		rotate_a_forward(stack, nbrs, to_move);
	else
		rotate_a_backward(stack, nbrs, to_move);
}

void			move_nbrs_to_b(t_stack *a, t_stack *b, t_nbrs_to_move *nbrs)
{
	t_min_nbr		*closest;

	while (a->nodes_amount > 3)
	{
		nbrs->max_amount = a->nodes_amount / 4;
		nbrs->curr_amount = 0;
		while (a->nodes_amount - nbrs->curr_amount > 3 &&
				nbrs->curr_amount < nbrs->max_amount)
			find_next_min(a, nbrs);
		while (nbrs->curr_amount)
		{
			closest = find_closest(a, nbrs);
			prepare_a_to_pb(a, nbrs, closest);
			op_handler(a, b, "pb");
			remove_node_from_nbrs_to_move_list(a, nbrs, closest);
		}
	}
}
