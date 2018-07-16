/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_nbrs_in_stack_a.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:05:33 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/16 12:05:58 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
		op_handler(stack, NULL, "sa");
		op_handler(stack, NULL, "rra");
	}
	else if (n1 > n3 && n3 > n2)
		op_handler(stack, NULL, "ra");
	else if (n2 > n1 && n1 > n3)
		op_handler(stack, NULL, "rra");
	else if (n2 > n3 && n3 > n1)
	{
		op_handler(stack, NULL, "sa");
		op_handler(stack, NULL, "ra");
	}
	else if (n3 > n1 && n1 > n2)
		op_handler(stack, NULL, "sa");
}
