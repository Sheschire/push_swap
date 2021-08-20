/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:47:56 by tlemesle          #+#    #+#             */
/*   Updated: 2021/08/20 13:01:34 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	
	if (!check_argv(ac, av))
		_err();
	if (!init_stack(&a, &b, av))
		_err();
	fill_a(&a, av);
}