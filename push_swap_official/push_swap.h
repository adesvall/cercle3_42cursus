/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:01:45 by adesvall          #+#    #+#             */
/*   Updated: 2021/06/26 16:02:27 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "srcs/get_next_line/get_next_line.h"

typedef struct s_args
{
	int	*a;
	int	*sep;
	int	len;
	int	*sorted;
	int	m;
	int	m_length;
	int	n_rt;
}				t_args;

int		*argv_to_tab(int argc, char **argv);
int		check_sort(int *a, int sep, int len);
void	copy_tab(int *a, int *b, int len);
void	print_tab(int *a, int sep, int len);
int		get_index(int *t, int n, int len);

int		ft_swap_a(int *a, int sep, int len, int disp);
int		ft_swap_b(int *a, int sep, int len, int disp);
int		ft_push_a(int *sep, int len, int disp);
int		ft_push_b(int *sep, int len, int disp);
int		ft_rotate_a(int *a, int sep, int len, int disp);
int		ft_rotate_b(int *a, int sep, int len, int disp);
int		ft_reverse_rotate_a(int *a, int sep, int len, int disp);
int		ft_reverse_rotate_b(int *a, int sep, int len, int disp);

int		min_finder(int *a, int sep);
int		max_finder(int *a, int sep);
void	sort_3(int *a, int len);
void	sort_5(int *a, int len, int *sorted);
void	sort_morceaux(int *a, int len, int mX, int *sorted);

#endif