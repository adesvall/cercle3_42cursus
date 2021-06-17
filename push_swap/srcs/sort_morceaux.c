/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_500.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:41:51 by adesvall          #+#    #+#             */
/*   Updated: 2021/06/16 23:54:52 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		abs(int	n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int		closest_finder(int min_index, int max_index, int sep)
{
	if (abs(2 * min_index - sep) < abs(2 * max_index - sep)) // verifier formule
		return (max_index);
	return (min_index);
}

int		find_closest_and_push_it_to_a(int *a, int *sep, int len)
{
	int closest;
	int	i;
	int min_rotations;

	min_rotations = 0;
	closest = closest_finder(min_finder(a, *sep), max_finder(a, *sep), *sep);
	i = 0;
	if (closest >= *sep / 2)
	{
		while (i++ < *sep - 1 - closest)
			ft_rotate_b(a, *sep, len);
	}
	else
	{
		while (i++ < closest + 1)
			ft_reverse_rotate_b(a, *sep, len);
	}
	ft_push_a(sep, len);
	if (*sep > 0 && a[*sep] < a[*sep - 1])
	{
		ft_rotate_a(a, *sep, len);
		min_rotations++;
	}
	return (min_rotations);
}

void	sort_morceaux(int *a, int len, int mX, int *sorted)
{
	int m;
	int i;
	int sep;
	int longueurdunmorceau;
	int min_rotation;

	sep = 0;
	m = 0;
	min_rotation = 0;
	longueurdunmorceau = len / mX + (len % mX != 0);
	while (m < mX)
	{
		//rajouter opti de si ccest le premier morceau et si cest le dernier

		if (min_rotation + 2 * (mX-m) * longueurdunmorceau <= len - min_rotation)
		{
			i=0;
			while (i < min_rotation + (mX-m)*longueurdunmorceau)
			{
				ft_reverse_rotate_a(a, sep, len);
				i++;
			}
			min_rotation = len - (mX-m)*longueurdunmorceau;
		}
		i = 0;
		while (i < len - min_rotation)
		{
			if (a[sep] >= sorted[(mX - m - 1) * longueurdunmorceau]
				&& (m == 0 || a[sep] < sorted[(mX - m) * longueurdunmorceau]))
				ft_push_b(&sep, len);
			else
				ft_rotate_a(a, sep, len);
			i++;
		}
		// print_tab(a, sep, len);
		min_rotation = 0;
		while (sep > 0)
			min_rotation += find_closest_and_push_it_to_a(a, &sep, len);
		// print_tab(a, sep, len);
		m++;
	}
	while (a[len - 1] < a[0])
		ft_reverse_rotate_a(a, sep, len);
}

/*
* 1. mettre tout les plus gros dans b
* 2. les remettre dans a de facon a ce quil soit triée
* 3. repeter l'operation pour toute les parties
*/