/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:43:34 by adesvall          #+#    #+#             */
/*   Updated: 2021/06/18 12:58:43 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(int *a, int sep, int len)
{
	int	i;

	i = 0;
	if (sep)
		return (0);
	while (i < len - 1)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_swap_a(int *a, int sep, int len, int disp)
{
	int	tmp;

	if (len - sep >= 2)
	{
		tmp = a[sep];
		a[sep] = a[sep + 1];
		a[sep + 1] = tmp;
		if (disp)
			printf("sa\n");
		return (1);
	}
	return (0);
}

int	ft_swap_b(int *a, int sep, int len, int disp)
{
	int	tmp;

	(void)len;
	if (sep >= 2)
	{
		tmp = a[sep - 1];
		a[sep - 1] = a[sep - 2];
		a[sep - 2] = tmp;
		if (disp)
			printf("sb\n");
		return (1);
	}
	return (0);
}

int	ft_push_a(int *sep, int len, int disp)
{
	(void)len;
	if (*sep == 0)
		return (0);
	(*sep)--;
	if (disp)
		printf("pa\n");
	return (1);
}

int	ft_push_b(int *sep, int len, int disp)
{
	if (*sep == len - 1)
		return (0);
	(*sep)++;
	if (disp)
		printf("pb\n");
	return (1);
}
