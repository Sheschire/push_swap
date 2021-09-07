/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_rrr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:22:17 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/07 14:06:58 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a, "");
	reverse_rotate(b, "");
	printf("rrr\n");
}
void    reverse_rotate(t_stack **s, char *move)
{
	t_stack *last;
	t_stack *to_add_front;
	
	last = *s;
	to_add_front = 0;
	while (last->n)
	{
		if (last->n)
		{
			if (last->n->n == NULL)
			{
				to_add_front = last->n;
				last->n = NULL;
			}
		}
		if (last->n)
			last = last->n;
	}
	add_front(s, to_add_front);
	if (move)
		printf("%s\n", move);
}