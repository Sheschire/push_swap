/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 12:58:07 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/09 17:41:07 by tlemesle         ###   ########.fr       */
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

int		check_bulk_range_top(t_stack **a, int start, int end, int ac)
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
int		check_bulk_range_bot(t_stack **rev, int start, int end, int ac)
{
	t_stack	*tmp;
	int	i;
	
	tmp = *rev;
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

void	big_sort(t_stack **a, t_stack **b, int ac)
{
	int	dist_up;
	int	dist_down;
	int	bulk_begin;
	int	bulk_size;
	t_stack	*rev;

	rev = 0;
	dist_up = 0;
	dist_down = 0;
	bulk_begin = 0;
	bulk_size = get_bulksize(ac);
//	while (*a)
//	{
		while (dist_up != -1 && dist_down != -1)
		{
			reverse_stack(&rev, a);
			dist_up = check_bulk_range_top(a, bulk_begin, bulk_size, ac);
			dist_down = check_bulk_range_bot(&rev, bulk_begin, bulk_size, ac);
			printf("bulksize = %d\ndist_up = %d\ndist_down = %d\n", bulk_size, dist_up, dist_down);
			print_stacks(a, b, 3);
			getchar();
			if (dist_up <= dist_down)
				rotate_push(a, b, dist_up, 1);
			if (dist_up > dist_down)
				rotate_push(a, b, dist_down, 0);
		}
		bulk_begin+= bulk_size;
		bulk_size+= bulk_size;
//	}
	print_stacks(a, b, 3);
}