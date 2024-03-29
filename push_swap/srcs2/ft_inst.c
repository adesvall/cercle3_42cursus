/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:43:34 by adesvall          #+#    #+#             */
/*   Updated: 2021/03/14 19:00:46 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_sort(t_stk *a)
{
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_swap(t_stk *a)
{
	int tmp;

	if (ft_stklen(a) >= 2)
	{
		tmp = a->content;
		a->content = a->next->content;
		a->next->content = tmp;
		tmp = a->target;
		a->target = a->next->target;
		a->next->target = tmp;
	}
}

void	ft_push(t_stk **a, t_stk **b)
{
	t_stk	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		ft_stkadd_top(a, tmp);
	}
}

void	ft_rotate(t_stk **a)
{
	t_stk	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	ft_stkadd_back(a, tmp);
	tmp->next = NULL;
}

void	ft_reverse_rotate(t_stk **a)
{
	t_stk	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_stkadd_top(a, tmp->next);
	tmp->next = NULL;
}
