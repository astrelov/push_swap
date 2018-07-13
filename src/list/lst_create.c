/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:42:33 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 14:46:24 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	lst_create(t_stack *stack, const int *nbrs)
{
	int 	i;
	t_node	*new_node;

	i = 0;
	while (i < g_total_nbrs_amnt)
	{
		new_node = lst_new_node(nbrs[i]);
		lst_push(stack, new_node);
		i++;
	}
}
