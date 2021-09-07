/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:54:28 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/07 15:16:11 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **a, t_stack **b)
{
	int	top;
	int	mid;
	int	bot;
	
	
}

void    sort_stacks(t_stack **a, t_stack **b, int ac)
{
	if (ac == 3)
		if ((*a)->v > (*a)->n->v)
			swap(a, "sa");
	if (ac == 4)
		sort_three(a, b);
}