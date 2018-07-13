/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:41:39 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 14:45:51 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack *stack)
{
	if (!g_checker)
		write(1, "rra\n", 4);
	if (!stack || !stack->nodes_amount)
		return;
	HEAD = HEAD->prev;
}

void	rrb(t_stack *stack)
{
	if (!g_checker)
		write(1, "rrb\n", 4);
	if (!stack || !stack->nodes_amount)
		return;
	HEAD = HEAD->prev;
}
