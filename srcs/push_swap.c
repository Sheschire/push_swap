/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:47:56 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/22 14:05:48 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_argv2(char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[++i])
	{
		j = -1;
		if (!ft_atoi(av[i]) && av[i][0] != '0')
			return (0);
		while (av[i][++j])
		{
			if (j == 0 && av[i][j] == '-')
				j++;
			if (!ft_isdigit(av[i][j]))
				return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (!check_argv(ac, av) || !check_argv2(av))
		_err();
	fill_a(&a, av);
	if (is_sorted(&a, &b))
	{
		free_stack(&a);
		exit(0);
	}
	update_stack_index(&a, av, ac - 1);
	is_sorted(&a, &b);
	sort_stacks(&a, &b, ac - 1);
	free_stack(&a);
}
