/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:49:03 by tlemesle          #+#    #+#             */
/*   Updated: 2021/08/20 13:02:48 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct  		s_stack
{
	int					v;
	int					p;
	struct s_stack		*n;
}						t_stack;

int		check_argv(int ac, char **av);
int		init_stack(t_stack *a, t_stack *b, char **av);
void	fill_a(t_stack *a, char **av);
void	_err(void);
#endif