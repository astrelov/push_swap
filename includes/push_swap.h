/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:28:12 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/14 15:32:18 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

#include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

# define HEAD 			(stack->head)

# define UNSORTED 		0
# define SORTED 		1

# define INVALID		0
# define VALID			1

size_t					g_total_nbrs_amnt;
size_t					g_checker;

typedef struct			s_node
{
	int					nbr;
	struct s_node		*prev;
	struct s_node		*next;
}						t_node;

typedef struct			s_stack
{
	t_node				*head;
	int					nodes_amount;
}						t_stack;

typedef struct			s_min_nbr
{
	int					index;
	t_node				*node;
	struct s_min_nbr	*next;
}						t_min_nbr;

typedef struct			s_nbrs_to_move
{
	int					curr_amount;
	int					max_amount;
	t_min_nbr			*nbrs_positions;
}						t_nbrs_to_move;

/*
** Helpers
*/

void					error(void);
int						input_is_valid(char **av);
int						*get_nbrs(char **av);
void					find_min(t_stack *stack, t_min_nbr *min);
t_min_nbr				*find_max(t_stack *stack);
void					find_next_min(t_stack *stack, t_nbrs_to_move *nbrs);
void					move_nbrs_to_b(t_stack *a, t_stack *b,
								t_nbrs_to_move *nbrs);
t_min_nbr				*find_closest(t_stack *a, t_nbrs_to_move *nbrs);
void					free_node(t_stack *stack, t_nbrs_to_move *nbrs,
								t_min_nbr *to_free);
void					prepare_a_to_pb(t_stack *stack, t_nbrs_to_move *nbrs,
								t_min_nbr *to_move);

/*
** Functions to manipulate list
*/

t_node					*lst_new_node(int nbr);
t_node					*lst_pop(t_stack *stack);
t_node					*lst_shift(t_stack *stack);
t_node					*lst_splice(t_stack *stack, t_node *node);
void					lst_push(t_stack *stack, t_node *node);
void					lst_create(t_stack *stack, const int *nbrs);
void					lst_push_head(t_stack *stack, t_node *node);
int						lst_is_sorted(t_stack *stack);

/*
** Available operations
*/

void					sa(t_stack *stack);
void					pa(t_stack *a, t_stack *b);
void					pb(t_stack *a, t_stack *b);
void					ra(t_stack *stack);
void					rb(t_stack *stack);
void					rra(t_stack *stack);
void					rrb(t_stack *stack);

#endif
