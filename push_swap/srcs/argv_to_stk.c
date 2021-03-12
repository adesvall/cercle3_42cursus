/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_to_stk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 18:20:37 by adesvall          #+#    #+#             */
/*   Updated: 2021/03/12 16:52:03 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_atoi_with_overflow_check(const char *str, int *n)
{
	unsigned int	res;
	int				i;
	int				sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i])
	{
		if (res > 214748364)
			return (0);
		res *= 10;
		if ((sign == 1) ? res > (unsigned int)(2147483647 - (str[i] - '0'))
						: res > (unsigned int)(2147483648 - (str[i] - '0')))
			return (0);
		res += str[i] - '0';
		i++;
	}
	*n = res * sign;
	return (1);
}

int		is_valid(char *str, t_stk *a, int *n)
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
	while (a)
	{
		if (a->content == *n)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stk	*argv_to_stk(int argc, char **argv)
{
	t_stk	*a;
	int		i;
	int		n;

	a = NULL;
	i = 1;
	while (i < argc)
	{
		if (!is_valid(argv[i], a, &n))
		{
			ft_stkclear(&a);
			return (NULL);
		}
		ft_stkadd_back(&a, ft_stknew(n));
		i++;
	}
	return (a);
}
