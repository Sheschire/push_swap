/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:54:28 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/08 14:02:58 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;
	
	top = (*a)->pos;
	mid = (*a)->n->pos;
	bot = (*a)->n->n->pos;
	if (top > mid && top < bot && mid < bot)
		swap(a, "sa");
	else if (top > mid && top > bot && mid > bot)
	{
		swap(a, "sa");
		reverse_rotate(a, "rra");
	}
	else if (top < mid && top < bot && mid > bot)
	{
		swap(a, "sa");
		rotate(a, "rra");
	}
	else if (top > mid && top > bot && mid < bot)
		rotate(a, "ra");
	else if (top < mid && top > bot && mid > bot)
		reverse_rotate(a, "rra");
}

void	sort_four_five(t_stack **a, t_stack **b, int ac)
{
	int	min_in_stack;
	int	push_limit;

	push_limit = 2;
	if (ac == 4)
		push_limit = 1;
	min_in_stack = 0;
	while (min_in_stack < push_limit)
	{
		while ((*a)->pos != min_in_stack)
			rotate(a, "ra");
		if ((*a)->pos == min_in_stack)
		{
			push(a, b, "pb");
			min_in_stack++;
		}
	}
	sort_three(a);
	push(b, a, "pa");
	if (push_limit == 2)
		push(b, a, "pa");
}

void    sort_stacks(t_stack **a, t_stack **b, int ac)
{
	if (ac == 2)
		if ((*a)->v > (*a)->n->v)
			swap(a, "sa");
	if (ac == 3)
		sort_three(a);
	if (ac == 4 || ac == 5)
		sort_four_five(a, b, ac);
	if (ac > 5)
		big_sort(a, b, ac);
}