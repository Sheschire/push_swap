/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 12:11:18 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/10 12:13:48 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_push(t_stack **a, t_stack **b, int dist, int dir)
{
	int	i;

	i = -1;
	if (dir == 1)
		while (++i < dist)
			rotate(a, "ra");
	if (dir == 0)
		while (++i < dist + 1)
			reverse_rotate(a, "rra");
	push(a, b, "pb");
}

int	get_bulksize(int ac)
{
	int	bulk_size;

	if (ac >= 250)
		bulk_size = (ac / 10);
	if (ac >= 100 && ac < 250)
		bulk_size = (ac / 6);
	if (ac < 100 && ac > 10)
		bulk_size = (ac / 3);
	if (ac <= 10)
		bulk_size = (ac / 2);
	return (bulk_size);
}