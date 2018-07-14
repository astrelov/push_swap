/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astrelov <astrelov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:40:33 by astrelov          #+#    #+#             */
/*   Updated: 2018/07/14 14:44:01 by astrelov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check(t_stack *a, t_stack *b)
{
	char	*op;
	int		fd;

	fd = open("./output.txt", O_RDONLY);
	while (ft_gnl(fd, &op))
	{
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
		else if (ft_strequ(op, "rra"))
			rra(a);
		else if (ft_strequ(op, "rrb"))
			rrb(b);
		else
			;//error();
	}
}

int		main(int ac, char **av)
{
	int		*nbrs_arr;
	t_stack	a;
	t_stack	b;

	g_checker = 1;
	g_total_nbrs_amnt = ac - 1;
	if (!input_is_valid(av))
		error();
	ft_bzero(&a, sizeof(t_stack));
	ft_bzero(&b, sizeof(t_stack));
	nbrs_arr = get_nbrs(av);
	lst_create(&a, nbrs_arr);
	check(&a, &b);
	ft_memdel((void **)&nbrs_arr);
	if (lst_is_sorted(&a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (0);
}
