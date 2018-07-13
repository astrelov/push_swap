/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:41:14 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 14:44:33 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_min_list(t_nbrs_to_move *nbrs)
{
	t_min_nbr	*node;

	puts("**************************************************");
	printf("DEBUG: PRINT_MIN_LIST(): MAX_AMOUNT = %d\n", nbrs->max_amount);
	printf("DEBUG: PRINT_MIN_LIST(): CURR_AMOUNT = %d\n", nbrs->curr_amount);
	node = nbrs->nbrs_positions;
	while (node)
	{
		printf("number = %d,\tindex = %d\n", node->node->nbr, node->index);
		node = node->next;
	}
	puts("DEBUG END");
	puts("**************************************************");
}

void	case_three_nbrs(t_stack *stack)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = HEAD->nbr;
	n2 = HEAD->next->nbr;
	n3 = HEAD->next->next->nbr;
	if (n1 > n2 && n2 > n3)
	{
		sa(stack);
		rra(stack);
	}
	else if (n1 > n3 && n3 > n2)
		ra(stack);
	else if (n2 > n1 && n1 > n3)
		rra(stack);
	else if (n2 > n3 && n3 > n1)
	{
		sa(stack);
		ra(stack);
	}
	else if (n3 > n1 && n1 > n2)
		sa(stack);
}

void	find_next_max(t_stack *stack, t_nbrs_to_move *nbrs)
{
	t_min_nbr	*next_max;
	t_min_nbr	*prev_max;
	t_node		*node;
	int 		index;

	nbrs->curr_amount++;
	if (!(nbrs->curr_amount - 1))
	{
		nbrs->nbrs_positions = find_max(stack);
		return;
	}
	prev_max = nbrs->nbrs_positions;
	while (prev_max->next)
		prev_max = prev_max->next;

	next_max = (t_min_nbr *)ft_memalloc(sizeof(t_min_nbr));
	if (HEAD->nbr < prev_max->node->nbr)
	{
		next_max->node = HEAD;
		next_max->index = 0;
	}
	else
		find_min(stack, next_max);


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

t_min_nbr	*find_nbr_more_than_moving(t_stack *stack, t_min_nbr *to_move, t_min_nbr *max)
{
	t_min_nbr	*more;
	t_node		*tmp;
	int 		index;

	more = (t_min_nbr *)ft_memalloc(sizeof(t_min_nbr));
	if (HEAD->nbr > to_move->node->nbr)
	{
		more->node = HEAD;
		more->index = 0;
	}
	tmp = HEAD->next;
	index = 1;
	while (tmp != HEAD)
	{
		if (tmp->nbr > to_move->node->nbr && (!more->node || tmp->nbr < more->node->nbr))
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
	return (more);
}

static void		prepare_b_to_pa(t_stack *stack, t_nbrs_to_move *nbrs, t_min_nbr *to_move)
{
	t_min_nbr	*node;

	if (to_move->index < stack->nodes_amount / 2 + 1)
		while (to_move->index--)
		{
			rb(stack);
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
			rrb(stack);
			node = nbrs->nbrs_positions;
			while (node)
			{
				if (node != to_move)
					node->index = node->index == stack->nodes_amount - 1 ? 0 : node->index + 1;
				node = node->next;
			}
		}
}

static void		prepare_a_to_pa(t_stack *stack, t_min_nbr *to_move)
{
	t_min_nbr	*max;
	t_min_nbr	*more_than_to_move;

	if (!HEAD)
		return;
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

void 	move_nbrs_to_a(t_stack *a, t_stack *b, t_nbrs_to_move *nbrs)
{
	t_min_nbr	*closest;

	while (b->nodes_amount)
	{
		nbrs->max_amount = (int)ft_d_sqrt(g_total_nbrs_amnt);//22;
		while (b->nodes_amount - nbrs->curr_amount && nbrs->curr_amount < nbrs->max_amount)
			find_next_max(b, nbrs);
		while (nbrs->curr_amount)
		{
			closest = find_closest(b, nbrs);
			prepare_b_to_pa(b, nbrs, closest);
			prepare_a_to_pa(a, closest);
			pa(a, b);
			free_node(b, nbrs, closest);
		}
	}
}

void	move_nbrs_to_b(t_stack *a, t_stack *b, t_nbrs_to_move *nbrs)
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

void	fix_a_stack_head(t_stack *stack)
{
	while (HEAD->nbr > HEAD->prev->nbr)
		rra(stack);
}

void	sort(t_stack *a, t_stack *b)
{
	t_nbrs_to_move	*nbrs;

	nbrs = (t_nbrs_to_move *)ft_memalloc(sizeof(t_nbrs_to_move));
	move_nbrs_to_b(a, b, nbrs);
	case_three_nbrs(a);
	move_nbrs_to_a(a, b, nbrs);
	fix_a_stack_head(a);
	ft_memdel((void **)&nbrs);
}

void	push_swap(char **av)
{
	int 	*nbrs_arr;
	t_stack	a;
	t_stack	b;

	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	nbrs_arr = get_nbrs(av);
	lst_create(&a, nbrs_arr);
	ft_memdel((void **)&nbrs_arr);
	sort(&a, &b);
}

int		main(int ac, char **av)
{
	g_total_nbrs_amnt = ac - 1;
	if (g_total_nbrs_amnt < 2)
		return (0);
	if (!input_is_valid(av))
		error();
	push_swap(av);
	return (0);
}
