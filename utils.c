/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:51:24 by tlemesle          #+#    #+#             */
/*   Updated: 2021/08/20 13:10:02 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    check_argv(int ac, char **av)
{
	int i;
	int j;
	
	i = 0;
	if (ac == 1)
		exit(0);
	while (av[++i])
	{
		j = -1;
		if (!ft_atoi(av[i]) && av[i][0] != '0')
			return (0);
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]))
				return (0);
	}
	i = 0;
	while (av[++i])
	{
		j = i;
		while (av[++j])
			if (!ft_strcmp(av[i], av[j]))
				return (0);
	}
	return (1);
}

void	_err(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

int		init_stack(t_stack *a, t_stack *b, char **av)
{
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	if (!a || !b)
		return (0);
	a = 0;
	b = 0;
	return (1);
}

void	fill_a(t_stack *a, char **av)
{
	int	i;

	i = 0;
	while (av[++i])
		a->v = ft_atoi(av[i]);
}
