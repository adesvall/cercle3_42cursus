/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:02:30 by adesvall          #+#    #+#             */
/*   Updated: 2021/05/16 15:13:15 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int correct_insertsort(int *t, int sep, int len)
{
	int	i;
	
	if (sep == 0)
		return (1);
	if (!check_sort(t, 0, sep+1))
		return (0);
	// si la pile b est triée,
	// alors ce seront les minimums ssi le sommet de b < toute la pile a
	i = sep;
	while (i < len)
	{
		if (t[sep-1] > t[i])
			return (0);
		i++;
	}
	return (1);
}

int insert_sort(int *a, int sep, int len)
{
	int min;
	int pos;
	int i;
	int count;
	int *t;

	count = 0;

	if (check_sort(a, 0, len))
		return (sep);
	t = malloc(len * sizeof(int));
	copy_tab(t, a, len);
	while (!correct_insertsort(t, sep, len))
	{
		ft_push_a(&sep, len);
		count++;
	}
	while (len - sep > 3)
	{
		pos = 0;
		min = t[sep];
		i = sep + 1;
		while (i < len)
		{
			if (t[i] < min)
			{
				min = t[i];
				pos = i;
			}
			i++;
		}
		while (pos != sep)
		{
			if (pos - sep < sep + (len - sep) / 2)
				ft_rotate_a(t, sep, len);
			else
				ft_reverse_rotate_a(t, sep, len);
			count++;
			pos = get_index(t, min, len);
			// print_tab(t, sep, len);
		}
		ft_push_b(&sep, len);
		count++;
	}
	if (check_sort(t, 0, len))
	{
		free(t);
		return (count + sep);
	}
	count++;
	if (len - sep == 3)
	{
		if (!( (t[sep+1] > t[sep] && t[sep+1] < t[sep+2])
		|| (t[sep+1] < t[sep] && t[sep+1] > t[sep+2])) )
			count++;
	}
	count+=sep;
	free(t);
	return (count);
	// if ()
	// {

	// }
	// while (sep > 0)
	// 	ft_push_a(&sep, len);
}