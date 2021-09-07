/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:51:24 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/07 17:43:38 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	fill_a(t_stack **a, char **av)
{
	int		i;
	t_stack *tmp;

	i = 0;
	while (av[++i])
	{
		tmp = newnode(ft_atoi(av[i]), i);
		add_back(a, tmp);
	}
}

void	print_stacks(t_stack **a, t_stack **b, int n)
{
	t_stack *tmp;

	tmp = 0;
	if (n == 1 || n == 3)
	{
		tmp = *a;
		printf("A\n_\n\n")	;
		while (tmp)
		{
			printf("%d      index : %d\n", tmp->v, tmp->pos);
			tmp = tmp->n;
		}
		printf("_\n");
		if (n == 3)
			printf("\n---------------------------------------\n\n");
	}
	if (n == 2 || n == 3)
	{
		tmp = *b;
		printf("B\n_\n\n")	;
		while (tmp)
		{
			if (tmp->v)
				printf("%d      index : %d\n", tmp->v, tmp->pos);
			tmp = tmp->n;
		}
		printf("_\n");
	}
}
