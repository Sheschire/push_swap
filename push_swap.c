/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:47:56 by tlemesle          #+#    #+#             */
/*   Updated: 2021/08/19 13:45:17 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	s;
	
	if (!check_argv(ac, av))
		write(1, "Error\n", 6);
	if (!init_stack(&s))
		write(1, "Error\n", 6);
	if (!fill_a(&s, av))
		write(1, "Error\n", 6);
}