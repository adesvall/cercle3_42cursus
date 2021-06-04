/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:01:45 by adesvall          #+#    #+#             */
/*   Updated: 2021/05/16 14:58:40 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "srcs/get_next_line/get_next_line.h"

# define MAX_LEAP 5

typedef struct	s_info
{
	int	 len;
	int (**fonct)();
	int (**invf)();
	char **list;
	char **invl;
	char **special;
	char **invspecial;
	char **inst;
	int	best_dist;
	char **inst_res;
	int *tab_res;
	int	sep_res;
	int step_res;
}				t_info;

int		*argv_to_tab(int argc, char **argv);
void	exec_inst(int *a, t_list *inst);

int		check_sort(int *a, int sep, int len);
int		ft_swap_a(int *a, int sep, int len);
int		ft_swap_b(int *a, int sep, int len);
int		ft_push_a(int *sep, int len);
int		ft_push_b(int *sep, int len);
int		ft_rotate_a(int *a, int sep, int len);
int		ft_rotate_b(int *a, int sep, int len);
int		ft_reverse_rotate_a(int *a, int sep, int len);
int		ft_reverse_rotate_b(int *a, int sep, int len);
void	copy_tab(int *a, int *b, int len);
void	print_tab(int *a, int sep, int len);
int 	get_index(int *t, int n, int len);

int		solve_inst(int *a, int sep, int step, t_info *info, int maxstep);
int 	insert_sort(int *a, int sep, int len);



#endif