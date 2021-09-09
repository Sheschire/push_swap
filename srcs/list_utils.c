/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 13:42:47 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/08 14:42:45 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack *newnode(int v, int pos)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (0);
	new->v = v;
	new->pos = pos;
	new->n = NULL;
	return (new);
}

void	add_back(t_stack **s, t_stack *new)
{
	t_stack	*last;

	if (s == NULL)
		return ;
	last = *s;
	if (*s == NULL)
		*s = new;
	else
	{
		while (last->n)
			last = last->n;
		last->n = new;
		new->n = NULL;
	}
}

void	add_front(t_stack **s, t_stack *new)
{
	if (new && s)
	{
		new->n = *s;
		*s = new;
	}
}

t_stack	*getlast(t_stack *s)
{
	if (s == NULL)
		return (0);
	while (s->n)
		s = s->n;
	return (s);
}