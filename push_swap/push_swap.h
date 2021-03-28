/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:01:45 by adesvall          #+#    #+#             */
/*   Updated: 2021/03/14 19:00:57 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "srcs/get_next_line/get_next_line.h"

typedef struct	s_stk
{
	int				content;
	int				target;
	struct s_stk	*next;
}				t_stk;

t_stk	*argv_to_stk(int argc, char **argv);
void	exec_inst(t_stk **a, t_list *inst);

t_stk	*ft_stknew(int content);
int		ft_stklen(t_stk *stk);
void	ft_stkadd_top(t_stk **stk, t_stk *new);
void	ft_stkadd_back(t_stk **stk, t_stk *new);
void	ft_stkclear(t_stk **stk);
t_stk	*ft_stkget_last(t_stk *a);
void	print_stk(t_stk *a, char *id);

int		check_sort(t_stk *a);
void	ft_swap(t_stk *a);
void	ft_push(t_stk **a, t_stk **b);
void	ft_rotate(t_stk **a);
void	ft_reverse_rotate(t_stk **a);

#endif