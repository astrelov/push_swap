/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_nbrs_to_a_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:40:08 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/15 11:14:06 by null             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	prepare_a_to_pa(t_stack *stack, t_min_nbr *to_move)
{
	t_min_nbr	*max;
	t_min_nbr	*more_than_to_move;

	max = find_max(stack);
	more_than_to_move = find_nbr_more_than_moving(stack, to_move, max);
	if (more_than_to_move->index < stack->nodes_amount / 2 + 1)
		while (more_than_to_move->index-- > 0)
			op_handler(stack, NULL, "ra");
	else
		while (stack->nodes_amount - more_than_to_move->index++ > 0)
			op_handler(stack, NULL, "rra");
	ft_memdel((void **)&max);
	ft_memdel((void **)&more_than_to_move);
}

void	prepare_a_b_to_pa(t_stack *a, t_stack *b, t_nbrs_to_move *nbrs,
						t_min_nbr *to_move)
{
	t_min_nbr	*max;
	t_min_nbr	*more_than_to_move;

	max = find_max(a);
	more_than_to_move = find_nbr_more_than_moving(a, to_move, max);
	if ((to_move->index < b->nodes_amount / 2 + 1) &&
						(more_than_to_move->index < a->nodes_amount / 2 + 1))
		while (to_move->index && more_than_to_move->index)
		{
			op_handler(a, b, "rr");
			1 ? to_move->index-- : more_than_to_move->index--;
			decrease_nbrs_indexes(b, nbrs, to_move);
		}
	else if ((to_move->index > b->nodes_amount / 2 + 1) &&
						(more_than_to_move->index > a->nodes_amount / 2 + 1))
		while (b->nodes_amount - to_move->index &&
				a->nodes_amount - more_than_to_move->index)
		{
			op_handler(a, b, "rrr");
			to_move->index++;
			more_than_to_move->index++;
			increase_nbrs_indexes(b, nbrs, to_move);
		}
	ft_memdel((void **)&max);
	ft_memdel((void **)&more_than_to_move);
}

void	fix_a_stack_head(t_stack *stack)
{
	while (HEAD->nbr > HEAD->prev->nbr)
		op_handler(stack, NULL, "rra");
}
