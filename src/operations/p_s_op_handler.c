/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_s_op_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 12:05:03 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/16 12:05:03 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	op_handler(t_stack *a, t_stack *b, char *op)
{
	ft_putendl(op);
	if (ft_strequ(op, "sa"))
		sa(a);
	else if (ft_strequ(op, "pa"))
		pa(a, b);
	else if (ft_strequ(op, "pb"))
		pb(a, b);
	else if (ft_strequ(op, "ra"))
		ra(a);
	else if (ft_strequ(op, "rb"))
		rb(b);
	else if (ft_strequ(op, "rr"))
		rr(a, b);
	else if (ft_strequ(op, "rra"))
		rra(a);
	else if (ft_strequ(op, "rrb"))
		rrb(b);
	else if (ft_strequ(op, "rrr"))
		rrr(a, b);
}
