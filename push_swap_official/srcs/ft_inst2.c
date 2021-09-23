/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:28:51 by adesvall          #+#    #+#             */
/*   Updated: 2021/06/18 12:59:42 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate_a(int *a, int sep, int len, int disp)
{
	int	tmp;
	int	i;

	if (len - sep < 2)
		return (0);
	tmp = a[sep];
	i = sep;
	while (i < len - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = tmp;
	if (disp)
		printf("ra\n");
	return (1);
}

int	ft_rotate_b(int *a, int sep, int len, int disp)
{
	int	tmp;
	int	i;

	(void)len;
	if (sep < 2)
		return (0);
	tmp = a[sep - 1];
	i = sep - 1;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = tmp;
	if (disp)
		printf("rb\n");
	return (1);
}

int	ft_reverse_rotate_a(int *a, int sep, int len, int disp)
{
	int	tmp;
	int	i;

	if (len - sep < 2)
		return (0);
	tmp = a[len - 1];
	i = len - 1;
	while (i > sep)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[i] = tmp;
	if (disp)
		printf("rra\n");
	return (1);
}

int	ft_reverse_rotate_b(int *a, int sep, int len, int disp)
{
	int	tmp;
	int	i;

	(void)len;
	if (sep < 2)
		return (0);
	tmp = a[0];
	i = 0;
	while (i < sep - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = tmp;
	if (disp)
		printf("rrb\n");
	return (1);
}
