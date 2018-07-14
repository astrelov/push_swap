/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 15:48:05 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 15:48:05 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

t_min_nbr	*find_closest(t_stack *a, t_nbrs_to_move *nbrs)
{
	int			moves;
	t_min_nbr	*node;
	t_min_nbr	*closest;

	closest = nbrs->nbrs_positions->next;
	moves = INT_MAX;
	node = nbrs->nbrs_positions;
	while (node)
	{
		if (node->index < moves)
		{
			moves = node->index;
			closest = node;
		}
		if (a->nodes_amount - node->index < moves)
		{
			moves = a->nodes_amount - node->index;
			closest = node;
		}
		node = node->next;
	}
	return (closest);
}

void		find_min(t_stack *stack, t_min_nbr *min)
{
	t_node	*node;
	int		index;

	min->index = 0;
	min->node = HEAD;
	node = HEAD->next;
	index = 1;
	while (node != HEAD)
	{
		if (node->nbr < min->node->nbr)
		{
			min->index = index;
			min->node = node;
		}
		node = node->next;
		index++;
	}
}

t_min_nbr	*find_max(t_stack *stack)
{
	int			index;
	t_min_nbr	*max;
	t_node		*node;

	max = (t_min_nbr *)ft_memalloc(sizeof(t_min_nbr));
	max->node = HEAD;
	max->index = 0;
	node = HEAD->next;
	index = 1;
	while (node != HEAD)
	{
		if (node->nbr > max->node->nbr)
		{
			max->index = index;
			max->node = node;
		}
		node = node->next;
		index++;
	}
	return (max);
}

void		find_next_min(t_stack *stack, t_nbrs_to_move *nbrs)
{
	t_min_nbr	*next_min;
	t_min_nbr	*prev_min;
	t_node		*node;
	int			index;

	next_min = (t_min_nbr *)ft_memalloc(sizeof(t_min_nbr));
	nbrs->curr_amount++;
	if (!(nbrs->curr_amount - 1))
	{
		find_min(stack, next_min);
		nbrs->nbrs_positions = next_min;
		return ;
	}
	prev_min = nbrs->nbrs_positions;
	while (prev_min->next)
		prev_min = prev_min->next;
	if (HEAD->nbr > prev_min->node->nbr)
	{
		next_min->node = HEAD;
		next_min->index = 0;
	}
	else
	{
		ft_memdel((void **)&next_min);
		next_min = find_max(stack);
	}
	prev_min->next = next_min;
	node = HEAD->next;
	index = 1;
	while (node != HEAD)
	{
		if (node->nbr > prev_min->node->nbr && node->nbr < next_min->node->nbr)
		{
			next_min->node = node;
			next_min->index = index;
		}
		index++;
		node = node->next;
	}
}
