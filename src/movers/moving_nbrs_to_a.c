/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_nbrs_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:27:42 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/15 10:05:46 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void			decrease_nbrs_indexes(t_stack *stack, t_nbrs_to_move *nbrs,
								t_min_nbr *to_move)
{
	t_min_nbr	*node;

	node = nbrs->nbrs_positions;
	while (node)
	{
		if (node != to_move)
			NIND = NIND ? NIND - 1 : stack->nodes_amount - 1;
		node = node->next;
	}
}

void			increase_nbrs_indexes(t_stack *stack, t_nbrs_to_move *nbrs,
								t_min_nbr *to_move)
{
	t_min_nbr	*node;

	node = nbrs->nbrs_positions;
	while (node)
	{
		if (node != to_move)
			NIND = NIND == stack->nodes_amount - 1 ? 0 : NIND + 1;
		node = node->next;
	}
}

static void		prepare_b_to_pa(t_stack *stack, t_nbrs_to_move *nbrs,
								t_min_nbr *to_move)
{
	if (to_move->index < stack->nodes_amount / 2 + 1)
		while (to_move->index-- > 0)
		{
			op_handler(NULL, stack, "rb");
			decrease_nbrs_indexes(stack, nbrs, to_move);
		}
	else
		while (stack->nodes_amount - to_move->index++ > 0)
		{
			op_handler(NULL, stack, "rrb");
			increase_nbrs_indexes(stack, nbrs, to_move);
		}
}

void			move_nbrs_to_a(t_stack *a, t_stack *b, t_nbrs_to_move *nbrs,
							int all_nbrs_amount)
{
	t_min_nbr	*closest;

	while (b->nodes_amount)
	{
		nbrs->max_amount = (int)ft_d_sqrt(all_nbrs_amount);
		while (b->nodes_amount - nbrs->curr_amount &&
				nbrs->curr_amount < nbrs->max_amount)
			find_next_max(b, nbrs);
		while (nbrs->curr_amount)
		{
			closest = find_closest(b, nbrs);
			prepare_a_b_to_pa(a, b, nbrs, closest);
			prepare_b_to_pa(b, nbrs, closest);
			prepare_a_to_pa(a, closest);
			op_handler(a, b, "pa");
			remove_node_from_nbrs_to_move_list(b, nbrs, closest);
		}
	}
}
