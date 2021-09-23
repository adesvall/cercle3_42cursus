/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:20:37 by adesvall          #+#    #+#             */
/*   Updated: 2021/09/15 19:01:55 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_with_overflow_check(const char *str, int *n)
{
	unsigned int	res;
	int				i;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i])
	{
		if (res > 214748364)
			return (0);
		res *= 10;
		if (res > (unsigned int)(2147483647 + (sign == -1) - (str[i] - '0')))
			return (0);
		res += str[i] - '0';
		i++;
	}
	*n = res * sign;
	return (1);
}

int	is_valid(char *str, int *a, int index, int *n)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	if (!ft_atoi_with_overflow_check(str, n))
		return (0);
	i = 0;
	while (i < index)
	{
		if (a[i] == *n)
			return (0);
		i++;
	}
	return (1);
}

int	*argv_to_tab(int argc, char **argv)
{
	int		*a;
	int		i;
	int		n;

	a = malloc(sizeof(int) * (argc - 1));
	if (a == NULL)
		return (NULL);
	i = 0;
	while (i < argc - 1)
	{
		if (!is_valid(argv[i + 1], a, i, &n))
		{
			free(a);
			return (NULL);
		}
		a[i] = n;
		i++;
	}
	return (a);
}
