/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:51:24 by tlemesle          #+#    #+#             */
/*   Updated: 2021/08/20 16:18:50 by tlemesle         ###   ########.fr       */
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

void	print_stacks(t_stack *a, t_stack *b, int n)
{
	t_stack *tmp;
	t_stack	*tmp2;

	tmp = 0;
	tmp2 = 0;
	if (n == 1 || n == 3)
	{
		tmp = a;
		printf("A\n_\n\n")	;
		while (a)
		{
			printf("%d\n", a->v);
			a = a->n;
		}
		printf("_\n");
		if (n == 3)
			printf("\n---------------------------------------\n\n");
	}
	if (n == 2 || n == 3)
	{
		tmp = b;
		printf("B\n_\n\n")	;
		while (b)
		{
			if (b->v)
				printf("%d\n", b->v);
			b = b->n;
		}
		printf("_\n");
	}
}

void	fill_a(t_stack *a, char **av)
{
	int		i;
	t_stack	*tmp;
	
	i = 1;
	tmp = a;
	a->v = ft_atoi(av[i]);
	while (av[++i])
	{
		a->n = newstack(ft_atoi(av[i]));
		a = a->n;
	}
	a = tmp;
}


