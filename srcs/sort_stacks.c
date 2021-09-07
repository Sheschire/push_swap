/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:54:28 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/07 18:26:16 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a, t_stack **b)
{
	int	top;
	int	mid;
	int	bot;
	
	top = (*a)->pos;
	mid = (*a)->n->pos;
	bot = (*a)->n->n->pos;
	if (top > mid && top < bot && mid < bot)
		swap(a, "sa");
	if (top > mid && top > bot && mid > bot)
	{
		swap(a, "sa");
		reverse_rotate(a, "rra");
	}
	if (top > mid && top > bot && mid < bot)
		rotate(a, "ra");
	if (top < mid && top < bot && mid > bot)
	{
		swap(a, "sa");
		rotate(a, "ra");
	}
	if (top < mid && top > bot && mid > bot)
		reverse_rotate(a, "rra");
}

void    sort_stacks(t_stack **a, t_stack **b, int ac)
{
	if (ac == 3)
		if ((*a)->v > (*a)->n->v)
			swap(a, "sa");
	if (ac == 4)
		sort_three(a, b);
}