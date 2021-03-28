/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prout.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 20:45:32 by adesvall          #+#    #+#             */
/*   Updated: 2021/03/21 18:42:05 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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
