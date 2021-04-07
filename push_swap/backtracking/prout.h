/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prout.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:45:32 by adesvall          #+#    #+#             */
/*   Updated: 2021/04/07 19:00:00 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEAP 9

typedef struct	s_info
{
	int	 len;
	int	*sorted;
	int (**fonct)();
	int (**invf)();
	char **list;
	char **invl;
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
