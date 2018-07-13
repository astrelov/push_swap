/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:41:33 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 14:45:48 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack *stack)
{
	if (!g_checker)
		write(1, "ra\n", 3);
	if (!stack->nodes_amount)
		return;
	HEAD = HEAD->next;
}

void	rb(t_stack *stack)
{
	if (!g_checker)
		write(1, "rb\n", 3);
	if (!stack->nodes_amount)
		return;
	HEAD = HEAD->next;
}
