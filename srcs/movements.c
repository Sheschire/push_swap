/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:25:43 by tlemesle          #+#    #+#             */
/*   Updated: 2021/08/20 17:26:47 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack *s, char c)
{
	int	tmp;

	if (s->n)
	{
		tmp = s->n->v;
		s->n->v = s->v;
		s->v = tmp;
		if (c == 'a')
			printf("sa\n");
		if (c == 'b')
			printf("sb\n");
	}
}

void	push(t_stack *src, t_stack *dst, char c)
{
	t_stack *tmp;

	tmp = src->n;
	add_front(src, dst);
	src = tmp;
}