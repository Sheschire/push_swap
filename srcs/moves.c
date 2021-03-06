/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 16:25:43 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/17 16:22:14 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **s, char *move)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*s && (*s)->n)
	{
		tmp = *s;
		tmp2 = (*s)->n;
		tmp->n = tmp2->n;
		tmp2->n = tmp;
		*s = tmp2;
		if (move)
		{
			ft_putstr_fd(move, 1);
			ft_putstr_fd("\n", 1);
		}
	}
}

void	reverse_rotate(t_stack **s, char *move)
{
	t_stack	*last;
	t_stack	*to_add_front;

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
	{
		ft_putstr_fd(move, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	rotate(t_stack **s, char *move)
{
	t_stack	*tmp;

	if ((*s)->n)
	{
		tmp = (*s)->n;
		add_back(s, *s);
		*s = tmp;
		if (move)
		{
			ft_putstr_fd(move, 1);
			ft_putstr_fd("\n", 1);
		}
	}
}

void	push(t_stack **src, t_stack **dst, char *move)
{
	t_stack	*tmp;

	if (*src)
	{
		tmp = (*src)->n;
		add_front(dst, *src);
		*src = tmp;
		ft_putstr_fd(move, 1);
		ft_putstr_fd("\n", 1);
	}
}
