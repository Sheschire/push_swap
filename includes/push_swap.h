/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:49:03 by tlemesle          #+#    #+#             */
/*   Updated: 2021/09/07 14:30:42 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct  		s_node
{
	int					v;
	int					pos;
	struct s_node		*n;
}						t_stack;

// UTILS
int		check_argv(int ac, char **av);
void	fill_a(t_stack **a, char **av);
void	_err(void);
void	print_stacks(t_stack **a, t_stack **b, int n);

// LIST UTILS
t_stack	*newnode(int v, int pos);
void	add_back(t_stack **s, t_stack *new);
void	add_front(t_stack **s, t_stack *new);

// MOVES
void	swap(t_stack **s, char *move);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **src, t_stack **dst, char *move);
void	rotate(t_stack **s, char *move);
void	rr(t_stack **a, t_stack **b);
void    reverse_rotate(t_stack **s, char *move);
void    rrr(t_stack **a, t_stack **b);

#endif