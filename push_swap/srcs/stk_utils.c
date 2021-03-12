/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:41:16 by adesvall          #+#    #+#             */
/*   Updated: 2021/03/12 15:57:01 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stk	*ft_stknew(int content)
{
	t_stk	*res;

	res = malloc(sizeof(t_stk));
	res->content = content;
	res->next = NULL;
	return (res);
}

int		ft_stklen(t_stk *stk)
{
	int i;

	i = 0;
	while (stk)
	{
		i++;
		stk = stk->next;
	}
	return i;
}

void	ft_stkadd_top(t_stk **stk, t_stk *new)
{
	if (!new)
		return ;
	new->next = *stk;
	*stk = new;
}

void	ft_stkadd_back(t_stk **stk, t_stk *new)
{
	while (*stk)
		stk = &((*stk)->next);
	*stk = new;
}

void	ft_stkclear(t_stk **stk)
{
	t_stk	*cur;

	cur = *stk;
	while (cur)
	{
		*stk = (*stk)->next;
		free(cur);
		cur = *stk;
	}
	*stk = 0;
}
