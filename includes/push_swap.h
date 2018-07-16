/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrielov <astrielov@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 20:28:12 by astrielov         #+#    #+#             */
/*   Updated: 2018/07/16 12:08:24 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include <limits.h>
# include "../libft/libft.h"

# define HEAD 			(stack->head)
# define NIND			(node->index)

# define UNSORTED 		0
# define SORTED 		1

# define INVALID		0
# define VALID			1

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
** Initiation
*/

int						input_is_valid(char **av, int nbrs_amount);
int						*get_nbrs(char **av, int amount);
void					error(void);

/*
** Proceeding
*/

void					move_nbrs_to_b(t_stack *a, t_stack *b,
									t_nbrs_to_move *nbrs);

void					case_three_nbrs(t_stack *stack);

void					prepare_a_to_pa(t_stack *stack, t_min_nbr *to_move);
void					prepare_a_b_to_pa(t_stack *a,
						t_stack *b, t_nbrs_to_move *nbrs, t_min_nbr *closest);
void					move_nbrs_to_a(t_stack *a, t_stack *b,
									t_nbrs_to_move *nbrs, int all_nbrs_amount);
void					fix_a_stack_head(t_stack *stack);

void					decrease_nbrs_indexes(t_stack *stack,
									t_nbrs_to_move *nbrs, t_min_nbr *to_move);
void					increase_nbrs_indexes(t_stack *stack,
									t_nbrs_to_move *nbrs, t_min_nbr *to_move);
void					remove_node_from_nbrs_to_move_list(t_stack *stack,
									t_nbrs_to_move *nbrs, t_min_nbr *to_free);
void					free_stack_nodes(t_stack *stack);

/*
** Finders
*/

void					find_next_min(t_stack *stack, t_nbrs_to_move *nbrs);
void					find_next_max(t_stack *stack, t_nbrs_to_move *nbrs);
t_min_nbr				*find_min(t_stack *stack);
t_min_nbr				*find_max(t_stack *stack);
t_min_nbr				*find_closest(t_stack *a, t_nbrs_to_move *nbrs);
t_min_nbr				*find_nbr_more_than_moving(t_stack *stack,
									t_min_nbr *to_move, t_min_nbr *max);

/*
** List
*/

t_node					*lst_new_node(int nbr);
t_node					*lst_pop(t_stack *stack);
t_node					*lst_shift(t_stack *stack);
t_node					*lst_splice(t_stack *stack, t_node *node);
void					lst_push(t_stack *stack, t_node *node);
void					lst_create(t_stack *stack, const int *nbrs,
								int nbrs_amount);
void					lst_push_head(t_stack *stack, t_node *node);
int						lst_is_sorted(t_stack *stack, int all_nbrs_amount);

/*
** Available operations
*/

void					op_handler(t_stack *a, t_stack *b, char *op);
void					sa(t_stack *stack);
void					pa(t_stack *a, t_stack *b);
void					pb(t_stack *a, t_stack *b);
void					ra(t_stack *stack);
void					rb(t_stack *stack);
void					rr(t_stack *a, t_stack *b);
void					rra(t_stack *stack);
void					rrb(t_stack *stack);
void					rrr(t_stack *a, t_stack *b);

#endif
