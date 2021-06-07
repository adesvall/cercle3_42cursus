/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:41:51 by adesvall          #+#    #+#             */
/*   Updated: 2021/06/07 22:40:33 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MORCEAUX 3
#include "push_swap.h"

int		abs(int	n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

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

int		closest_finder(int min_index, int max_index, int sep)
{
	if (abs(min_index - sep / 2) < abs(max_index - sep / 2))
		return (max_index);
	return (min_index);
}

void	find_closest_and_push_it_to_a(int *a, int *sep, int len)
{
	int closest;
	int	i;

	i = 0;
	closest = closest_finder(min_finder(a, *sep), max_finder(a, *sep), *sep);
	if (closest > *sep / 2)
	{
		while (i++ < *sep - closest)
			ft_reverse_rotate_b(a, *sep, len);
	}
	else
	{
		while (i++ < closest)
			ft_rotate_b(a, *sep, len);
	}
	ft_push_a(sep, len);
}

void	sort_500(int *a, int len, int *sorted)
{
	int morceau;
	int i;
	int sep;
	int longueurdunmorceau = len / MORCEAUX + (len % MORCEAUX != 0);

	sep = 0;
	morceau = 0;
	while (morceau < MORCEAUX)
	{
		i = 0;
		while (i < len)
		{
			if (a[sep] >= sorted[(MORCEAUX - morceau - 1) * longueurdunmorceau]
				&& (morceau == 0 || a[sep] < sorted[(MORCEAUX - morceau) * longueurdunmorceau]))
				ft_push_b(&sep, len);
			else
				ft_rotate_a(a, sep, len);
			i++;
		}
		while (sep > 0)
			find_closest_and_push_it_to_a(a, &sep, len);
		morceau++;
	}
}

/*
1. mettre tout les plus gros dans b
2. les remettre dans a de facon a ce quil soit triée
3. repeter l'operation pour toute les parties
*/