/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:42:44 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 14:45:16 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

t_node	*lst_new_node(int nbr)
{
	t_node	*el;

	if (!(el = (t_node *)ft_memalloc(sizeof(t_node))))
		return (NULL);
	el->nbr = nbr;
	return (el);
}
