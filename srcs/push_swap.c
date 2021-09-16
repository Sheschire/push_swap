/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:47:56 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/11 03:02:34 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (!check_argv(ac, av))
		_err();
	fill_a(&a, av);
	update_stack_index(&a, av, ac - 1);
	sort_stacks(&a, &b, ac - 1);
//	print_stacks(&a, &b, 3);
	free_stack(&a);
}