/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_nbrs_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:27:42 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 17:26:55 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void		prepare_a_to_pa(t_stack *stack, t_min_nbr *to_move)
{
	t_min_nbr	*max;
	t_min_nbr	*more_than_to_move;

	if (!HEAD)
		return ;
	max = find_max(stack);
	more_than_to_move = find_nbr_more_than_moving(stack, to_move, max);
	if (more_than_to_move->index < stack->nodes_amount / 2 + 1)
		while (more_than_to_move->index--)
			ra(stack);
	else
		while (stack->nodes_amount - more_than_to_move->index++)
			rra(stack);
	ft_memdel((void **)&max);
	ft_memdel((void **)&more_than_to_move);
}

static void		rotate_b_forward(t_stack *stack, t_nbrs_to_move *nbrs,
									t_min_nbr *to_move)
{
	t_min_nbr	*node;

	while (to_move->index--)
	{
		rb(stack);
		node = nbrs->nbrs_positions;
		while (node)
		{
			if (node != to_move)
				NIND = NIND ? NIND - 1 : stack->nodes_amount - 1;
			node = node->next;
		}
	}
}

static void		rotate_b_backward(t_stack *stack, t_nbrs_to_move *nbrs,
									t_min_nbr *to_move)
{
	t_min_nbr	*node;

	while (stack->nodes_amount - to_move->index++)
	{
		rrb(stack);
		node = nbrs->nbrs_positions;
		while (node)
		{
			if (node != to_move)
				NIND = NIND == stack->nodes_amount - 1 ? 0 : NIND + 1;
			node = node->next;
		}
	}
}

static void		prepare_b_to_pa(t_stack *stack, t_nbrs_to_move *nbrs,
								t_min_nbr *to_move)
{
	if (to_move->index < stack->nodes_amount / 2 + 1)
		rotate_b_forward(stack, nbrs, to_move);
	else
		rotate_b_backward(stack, nbrs, to_move);
}

void			move_nbrs_to_a(t_stack *a, t_stack *b, t_nbrs_to_move *nbrs)
{
	t_min_nbr	*closest;

	while (b->nodes_amount)
	{
		nbrs->max_amount = (int)ft_d_sqrt(g_total_nbrs_amnt);
		while (b->nodes_amount - nbrs->curr_amount &&
				nbrs->curr_amount < nbrs->max_amount)
			find_next_max(b, nbrs);
		while (nbrs->curr_amount)
		{
			closest = find_closest(b, nbrs);
			prepare_b_to_pa(b, nbrs, closest);
			prepare_a_to_pa(a, closest);
			pa(a, b);
			remove_node_from_nbrs_to_move_list(b, nbrs, closest);
		}
	}
}
