/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders_for_moving_to_a.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:45:51 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 17:19:14 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	check_for_greater_nbr(t_stack *stack, t_min_nbr *prev_max,
									t_min_nbr *next_max)
{
	t_node		*node;
	int			index;

	node = HEAD->next;
	index = 1;
	while (node != HEAD)
	{
		if (node->nbr < prev_max->node->nbr && node->nbr > next_max->node->nbr)
		{
			next_max->node = node;
			next_max->index = index;
		}
		index++;
		node = node->next;
	}
	prev_max->next = next_max;
}

void		find_next_max(t_stack *stack, t_nbrs_to_move *nbrs)
{
	t_min_nbr	*next_max;
	t_min_nbr	*prev_max;

	if (!nbrs->curr_amount++)
	{
		nbrs->nbrs_positions = find_max(stack);
		return ;
	}
	prev_max = nbrs->nbrs_positions;
	while (prev_max->next)
		prev_max = prev_max->next;
	if (HEAD->nbr < prev_max->node->nbr)
	{
		next_max = (t_min_nbr *)ft_memalloc(sizeof(t_min_nbr));
		next_max->node = HEAD;
		next_max->index = 0;
	}
	else
		next_max = find_min(stack);
	check_for_greater_nbr(stack, prev_max, next_max);
}

static void	check_for_better_node(t_stack *stack, t_min_nbr *to_move,
									t_min_nbr *max, t_min_nbr *more)
{
	t_node		*tmp;
	int			index;

	index = 1;
	tmp = HEAD->next;
	while (tmp != HEAD)
	{
		if (tmp->nbr > to_move->node->nbr &&
			(!more->node || tmp->nbr < more->node->nbr))
		{
			more->node = tmp;
			more->index = index;
		}
		tmp = tmp->next;
		index++;
	}
	if (!more->node)
	{
		more->node = max->node;
		more->index = max->index;
	}
}

t_min_nbr	*find_nbr_more_than_moving(t_stack *stack, t_min_nbr *to_move,
										t_min_nbr *max)
{
	t_min_nbr	*more;

	more = (t_min_nbr *)ft_memalloc(sizeof(t_min_nbr));
	if (HEAD->nbr > to_move->node->nbr)
	{
		more->node = HEAD;
		more->index = 0;
	}
	check_for_better_node(stack, to_move, max, more);
	return (more);
}
