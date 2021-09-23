/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 22:33:57 by adesvall          #+#    #+#             */
/*   Updated: 2021/06/18 15:42:10 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_finder(int *a, int sep)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < sep)
	{
		if (a[i] > a[max])
			max = i;
		i++;
	}
	return (max);
}

int	min_finder(int *a, int sep)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i < sep)
	{
		if (a[i] < a[min])
			min = i;
		i++;
	}
	return (min);
}

void	sort_3(int *a, int len)
{
	int	min;
	int	max;

	if (len == 2)
	{
		if (a[0] > a[1])
			ft_swap_a(a, 0, len, 1);
		return ;
	}
	min = min_finder(a, len);
	max = max_finder(a, len);
	if ((min + 1) % 3 == max)
		ft_swap_a(a, 0, len, 1);
	if (min == 2)
		ft_reverse_rotate_a(a, 0, len, 1);
	else if (max != 2)
		ft_rotate_a(a, 0, len, 1);
}

void	sort_5(int *a, int len, int *sorted)
{
	int	sep;
	int	min;
	int	max;

	sep = 0;
	while (len - sep > 3)
		ft_push_b(&sep, len, 1);
	min = min_finder(a + sep, len - sep);
	max = max_finder(a + sep, len - sep);
	if ((min + 1) % 3 == max)
		ft_swap_a(a, sep, len, 1);
	if (len == 5 && \
		a[sep - 2] == sorted[(get_index(sorted, a[sep - 1], len) + 1) % len])
		ft_swap_b(a, sep, len, 1);
	while (sep > 0)
		if (a[sep] == sorted[(get_index(sorted, a[sep - 1], len) + 1) % len])
			ft_push_a(&sep, len, 1);
	else
		ft_reverse_rotate_a(a, sep, len, 1);
	while (a[0] != sorted[0])
		if (get_index(sorted, a[0], len) * 2 < len)
			ft_reverse_rotate_a(a, sep, len, 1);
	else
		ft_rotate_a(a, sep, len, 1);
}
