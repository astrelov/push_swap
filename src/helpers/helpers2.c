/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:41:02 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 15:11:53 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int			input_is_valid(char **av)
{
	int		*nbrs;
	char	*nbr;
	int		i;
	int		equal;

	nbrs = get_nbrs(av);
	i = -1;
	while (++i < g_total_nbrs_amnt)
	{
		nbr = ft_itoa(nbrs[i]);
		equal = ft_strequ(nbr, *(av + i + 1));
		ft_memdel((void **)&nbr);
		if (!equal)
			return (INVALID);
	}
	ft_d_bblsort(nbrs, (size_t)g_total_nbrs_amnt);
	while (--i > 0)
		if (nbrs[i - 1] == nbrs[i])
		{
			printf("DUPLICATE: %d\n", nbrs[i]);
			ft_memdel((void **)&nbrs);
			return (INVALID);
		}
	ft_memdel((void **)&nbrs);
	return (VALID);
}

void		error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

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

void		prepare_a_to_pb(t_stack *stack, t_nbrs_to_move *nbrs,
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

void		free_node(t_stack *stack, t_nbrs_to_move *nbrs, t_min_nbr *to_free)
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
