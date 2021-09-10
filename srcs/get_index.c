/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 17:42:13 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/10 14:34:50 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

int		*create_sorted_tab(char **av, int ac)
{
	int	*tab;
	int	i;
	int	j;
	
	i = 0;
	j = -1;
	tab = (int *)malloc(sizeof(int) * ac);
	if (!tab)
		return (0);
	while (av[++i])
		tab[++j] = ft_atoi(av[i]);
	sort_int_tab(tab, ac);
	return (tab);
}

void	update_stack_index(t_stack **a, char **av, int ac)
{
	int	*tab;
	int	i;
	t_stack *tmp;

	tmp = *a;
	tab = create_sorted_tab(av, ac);
	while (tmp && i < ac)
	{
		i = 0;
		while (tab[i] != tmp->v)
			i++;
		if (tab[i] == tmp->v)
			tmp->pos = i;
		tmp = tmp->n;
	}
	free(tab);
}