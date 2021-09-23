/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_morceaux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:41:51 by adesvall          #+#    #+#             */
/*   Updated: 2021/09/15 19:04:42 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	closest_finder(int min_index, int max_index, int sep)
{
	if (abs(2 * min_index - sep) < abs(2 * max_index - sep))
		return (max_index);
	return (min_index);
}

int	find_closest_and_push_it_to_a(int *a, int *sep, int len)
{
	int	closest;
	int	i;
	int	min_rotations;

	min_rotations = 0;
	closest = closest_finder(min_finder(a, *sep), max_finder(a, *sep), *sep);
	i = 0;
	if (closest >= *sep / 2)
	{
		while (i++ < *sep - 1 - closest)
			ft_rotate_b(a, *sep, len, 1);
	}
	else
	{
		while (i++ < closest + 1)
			ft_reverse_rotate_b(a, *sep, len, 1);
	}
	ft_push_a(sep, len, 1);
	if (*sep > 0 && a[*sep] < a[*sep - 1])
	{
		ft_rotate_a(a, *sep, len, 1);
		min_rotations++;
	}
	return (min_rotations);
}

void	rotate_push(t_args info)
{
	int	i;

	i = 0;
	while (i < info.n_rt)
	{
		if (((info.m + 1) * info.m_length >= info.len || \
			info.a[*info.sep] >= \
				info.sorted[info.len - (info.m + 1) * info.m_length]) && \
			(info.m == 0 || \
			info.a[*info.sep] < info.sorted[info.len - info.m * info.m_length]))
			ft_push_b(info.sep, info.len, 1);
		else
			ft_rotate_a(info.a, *info.sep, info.len, 1);
		i++;
	}
}

void	sort_morceaux(int *a, int len, int m_length, int *sorted)
{
	int	m;
	int	i;
	int	sep;
	int	min_rot;

	sep = 0;
	m = 0;
	min_rot = 0;
	while (m * m_length < len)
	{
		if (min_rot + 2 * (len - m * m_length) <= len - min_rot)
		{
			i = 0;
			while (i++ < min_rot + (len - m * m_length))
				ft_reverse_rotate_a(a, sep, len, 1);
			min_rot = m * m_length;
		}
		rotate_push((t_args){a, &sep, len, sorted, m, m_length, len - min_rot});
		min_rot = 0;
		while (sep > 0)
			min_rot += find_closest_and_push_it_to_a(a, &sep, len);
		m++;
	}
	while (a[len - 1] < a[0])
		ft_reverse_rotate_a(a, sep, len, 1);
}

/*
* 1. mettre tout les plus gros dans b
* 2. les remettre dans a de facon a ce quil soit triée
* 3. repeter l'operation pour toute les parties
*/