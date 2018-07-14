/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_nbrs_to_a_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 16:40:08 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 16:40:08 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	fix_a_stack_head(t_stack *stack)
{
	while (HEAD->nbr > HEAD->prev->nbr)
		rra(stack);
}
