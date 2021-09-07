/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:25:43 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/07 14:26:55 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ss(t_stack **a, t_stack **b)
{
	swap(a, "");
	swap(b, "");
	printf("ss\n");
}

void	swap(t_stack **s, char *move)
{
	t_stack *tmp;
	t_stack *tmp2;
	
	if (*s && (*s)->n)
	{
		tmp = *s;
		tmp2 = (*s)->n;
		tmp->n = tmp2->n;
		tmp2->n = tmp;
		*s = tmp2;
		if (move)
			printf("%s\n", move);
	}
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a, "");
	rotate(b, "");
	printf("rr");
}

void	rotate(t_stack **s, char *move)
{
	t_stack *tmp;

	if ((*s)->n)
	{
		tmp = (*s)->n;
		add_back(s, *s);
		*s = tmp;
		if (move)
			printf("%s\n", move);
	}
}

void	push(t_stack **src, t_stack **dst, char *move)
{
	t_stack *tmp;

	if ((*src)->n)
	{
		tmp = (*src)->n;
		add_front(dst, *src);
		*src = tmp;
		printf("%s\n", move);
	}
}