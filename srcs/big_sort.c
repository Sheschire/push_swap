/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:58:07 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/09 14:10:10 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_in_half(t_stack **a, int bulksize, int start, int limit)
{
	t_stack	*tmp;
	int	i;
	
	tmp = *a;
	i = -1;
	while (++i < start)
		tmp = tmp->n;
	i = 0;
	while (tmp && start++ < limit)
	{
		if (tmp->pos >= )
			return (i);
		tmp = tmp->n;
		i++;
	}
	return (-1);
}

void	get_distance(t_stack **a, int bulk_size, int *dist, int ac)
{
	dist[1] = 0;
	dist[0] = check_in_half(a, bulk_size, 0, (ac / 2) + 1);
	if (dist[0] == -1)
	{
		dist[0] = (ac / 2) - check_in_half(a, bulk_size, ac / 2, ac);
		dist[1] = 1;
	}
}

void	big_sort(t_stack **a, t_stack **b, int ac)
{
	int	*dist1;
	int	*dist2;
	int	i;
	int	bulk_size;
	
	i = -1;
	bulk_size = get_bulksize(ac);
	dist1 = (int *)malloc(sizeof(int) * 2);
	dist2 = (int *)malloc(sizeof(int) * 2);
	if (!dist1 || !dist2)
		return ;
	while (*a)
	{
		get_distance(a, bulk_size, dist1, ac);
		get_distance(a, bulk_size, dist2, ac);
		if (dist1[0] < dist2[0])
			rotate_push(a, b, dist1);
		if (dist2[0] < dist1[0])
			rotate_push(a, b, dist2);
	}
	print_stacks(a, b, 3);
}