/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:40:48 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 14:44:41 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

void	print_stack(t_stack *stack)
{
	t_node	*node;

	puts("**************************************************");
	printf("DEBUG: PRINT_LIST(): stack_nodes = %d\n", stack->nodes_amount);
	if (!stack->nodes_amount)
	{
		puts("**************************************************");
		return;
	}
	node = HEAD;
	do {
		printf("node: nbr = %d\n", node->nbr);
		node = node->next;
	} while (node != HEAD);
	puts("**************************************************");
}

int 	*get_nbrs(char **av)
{
	int		*nbrs;
	int 	i;

	nbrs = (int *)ft_memalloc(g_total_nbrs_amnt * sizeof(int));
	i = 0;
	while (i < g_total_nbrs_amnt)
		nbrs[i++] = ft_atoi(*(++av));
	return nbrs;
}

void	find_min(t_stack *stack, t_min_nbr *min)
{
	t_node	*node;
	int 	index;

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
	int 		index;
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
	return max;
}

void	find_next_min(t_stack *stack, t_nbrs_to_move *nbrs)
{
	t_min_nbr	*next_min;
	t_min_nbr	*prev_min;
	t_node		*node;
	int 		index;

	next_min = (t_min_nbr *)ft_memalloc(sizeof(t_min_nbr));
	nbrs->curr_amount++;
	if (!(nbrs->curr_amount - 1))
	{
		find_min(stack, next_min);
		nbrs->nbrs_positions = next_min;
		return;
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
