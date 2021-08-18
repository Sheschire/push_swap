/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:51:24 by tlemesle          #+#    #+#             */
/*   Updated: 2021/08/18 10:57:03 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    check_argv(int ac, char **av)
{
	int i;
	int j;
	
	i = 0;
	if (ac < 2)
		return (0);
	while (av[++i]) 
	{
		j = -1;
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