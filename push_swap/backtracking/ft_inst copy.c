/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:43:34 by adesvall          #+#    #+#             */
/*   Updated: 2021/03/15 20:35:01 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_sort(int *a, int sep, int len)
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

int	ft_swap_a(int *a, int sep, int len)
{
	int tmp;

	if (len - sep >= 2)
	{
		tmp = a[sep];
		a[sep] = a[sep + 1];
		a[sep + 1] = tmp;
		return (1);
	}
	return (0);
}

int	ft_swap_b(int *a, int sep, int len)
{
	int tmp;

	if (sep >= 2)
	{
		tmp = a[sep - 1];
		a[sep - 1] = a[sep - 2];
		a[sep - 2] = tmp;
		return (1);
	}
	return (0);
}

int	ft_push_a(int *sep, int len)
{
	if (*sep == 0)
		return (0);
	(*sep)--;
	return (1);
}

int	ft_push_b(int *sep, int len)
{
	if (*sep == len - 1)
		return (0);
	(*sep)++;
	return (1);
}

int	ft_rotate_a(int *a, int sep, int len)
{
	int	tmp;
	int i;

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
	return (1);
}

int	ft_rotate_b(int *a, int sep, int len)
{
	int	tmp;
	int i;

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
	return (1);
}

int	ft_reverse_rotate_a(int *a, int sep, int len)
{
	int	tmp;
	int i;

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
	return (1);
}

int	ft_reverse_rotate_b(int *a, int sep, int len)
{
	int	tmp;
	int i;

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
	return (1);
}
