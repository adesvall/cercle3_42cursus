/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 22:33:57 by adesvall          #+#    #+#             */
/*   Updated: 2021/06/17 01:07:47 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		max_finder(int *a, int sep)
{
	int		i;
	int		max;

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

int		min_finder(int *a, int sep)
{
	int		i;
	int		min;

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
			ft_swap_a(a, 0, len);
		return ;
	}
	min = min_finder(a, len);
	max = max_finder(a, len);
	if ((min + 1) % 3 == max)	// si le sens est mauvais, un swap le change
		ft_swap_a(a, 0, len);
	if (min == 2)						// puis on tourne dans le bon sens si besoin
		ft_reverse_rotate_a(a, 0, len);
	else if (max != 2)
		ft_rotate_a(a, 0, len);
}

void	sort_5(int *a, int len, int *sorted)
{
	int sep;
	int min;
	int max;

	sep = 0;
	while (len - sep > 3)
		ft_push_b(&sep, len);
	min = min_finder(a + sep, len - sep);
	max = max_finder(a + sep, len - sep);
	if ((min + 1) % 3 == max)
		ft_swap_a(a, sep, len);
	if (len == 5 && a[sep - 2] == sorted[(get_index(sorted, a[sep - 1], len) + 1) % len])
		ft_swap_b(a, sep, len);
	while (sep > 0)
	{
		if (a[sep] == sorted[(get_index(sorted, a[sep - 1], len) + 1) % len])
			ft_push_a(&sep, len);
		else
			ft_reverse_rotate_a(a, sep, len); // choisir le bon sens !! ./push_swap 5 3 4 2 1 typiquement est dans le mauvais sens
	}
	while (a[0] != sorted[0])
	{
		if (get_index(sorted, a[0], len) * 2 < len)
			ft_reverse_rotate_a(a, sep, len);
		else
			ft_rotate_a(a, sep, len);
	}
}
