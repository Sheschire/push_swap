/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:58:07 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/10 12:23:10 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	copy_stack(t_stack **copy, t_stack **src)
{
	t_stack *tmp;
	t_stack *node;

	tmp = *src;
	while (tmp)
	{
		node = newnode(tmp->v, tmp->pos);
		add_back(copy, node);
		tmp = tmp->n;
	}
}

void	reverse_stack(t_stack **rev, t_stack **a)
{
	t_stack	*copy;
	t_stack	*tmp;
	
	copy = 0;
	copy_stack(&copy, a);
	while (copy)
	{
		tmp = copy->n;
		add_front(rev, copy);
		copy = tmp;
	}
}

int		check_bulk_range(t_stack **a, int start, int end, int ac)
{
	t_stack	*tmp;
	int	i;
	
	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->pos >= start && tmp->pos <= end)
			return (i);
		tmp = tmp->n;
		i++;
	}
	return (-1);
}

void	push_bulks_in_b(int bulk_size, t_stack **rev, int ac)
{
	int	dist_up;
	int	dist_down;
	int	bulk_begin;
	int	bulk_end;
	
	bulk_begin = 0;
	bulk_end = bulk_size;
	while (*a)
	{
		dist_up = 0;
		dist_down = 0;
		while (dist_up != -1 && dist_down != -1)
		{
			reverse_stack(&rev, a);
			dist_up = check_bulk_range(a, bulk_begin, bulk_end, ac);
			dist_down = check_bulk_range(&rev, bulk_begin, bulk_end, ac);
			if (dist_up <= dist_down && dist_down != -1 && dist_up != -1)
				rotate_push(a, b, dist_up, 1);
			if (dist_up > dist_down && dist_down != -1 && dist_up != -1)
				rotate_push(a, b, dist_down, 0);
			free_stack(&rev);
		}
		bulk_begin+= bulk_size;
		bulk_end+= bulk_size;
	}
}

void	big_sort(t_stack **a, t_stack **b, int ac)
{
	int	bulk_size;
	t_stack	*rev;

	rev = 0;
	bulk_size = get_bulksize(ac);
	push_bulks_in_b(bulk_size, &rev, ac);
	print_stacks(a, b, 3);
}