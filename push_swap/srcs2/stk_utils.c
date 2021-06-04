/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stk_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:41:16 by adesvall          #+#    #+#             */
/*   Updated: 2021/03/13 19:26:17 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stk(t_stk *a, char *id)
{
	printf("Stack %s :\n", id);
	if (!a)
		printf("Empty\n");
	while (a)
	{
		printf("= %d\n", a->content);
		a = a->next;
	}
}

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
	return (i);
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

t_stk	*ft_stkget_last(t_stk *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}