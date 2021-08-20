/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:51:24 by tlemesle          #+#    #+#             */
/*   Updated: 2021/08/19 13:52:23 by tlemesle         ###   ########.fr       */
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

int	init_stack(t_stack *s)
{
	s->a = (t_list **)malloc(sizeof(t_list));
	if (!s->a)
		return (0);
	s->b = (t_list **)malloc(sizeof(t_list));
	if (!s->b)
		return (0);
	s->a = 0;
	s->b = 0;
	return (1);
}

int	fill_a(t_stack *s, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		s->a.content = av[i];
	}
	return (1);
}