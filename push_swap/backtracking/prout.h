/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prout.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:45:32 by adesvall          #+#    #+#             */
/*   Updated: 2021/04/27 20:27:20 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEAP 7

typedef struct	s_info
{
	int	 len;
	int	*sorted;
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


int		check_sort(int *a, int sep, int len);
int	ft_swap_a(int *a, int sep, int len);
int	ft_swap_b(int *a, int sep, int len);
int	ft_push_a(int *sep, int len);
int	ft_push_b(int *sep, int len);
int	ft_rotate_a(int *a, int sep, int len);
int	ft_rotate_b(int *a, int sep, int len);
int	ft_reverse_rotate_a(int *a, int sep, int len);
int	ft_reverse_rotate_b(int *a, int sep, int len);
void	copy_tab(int *a, int *b, int len);
void	print_tab(int *a, int sep, int len);
int 	get_index(int *t, int n, int len);

int insert_sort(int *t, int *a, int sep, int len);
