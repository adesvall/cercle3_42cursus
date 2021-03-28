/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_inst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:30:18 by adesvall          #+#    #+#             */
/*   Updated: 2021/03/14 19:01:28 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_inst(t_stk **a, t_stk **b, char *str)
{
	if (!ft_strncmp(str, "sa", 2) || !ft_strncmp(str, "ss", 2))
		ft_swap(*a);
	if (!ft_strncmp(str, "sb", 2) || !ft_strncmp(str, "ss", 2))
		ft_swap(*b);
	if (!ft_strncmp(str, "pa", 2))
		ft_push(a, b);
	if (!ft_strncmp(str, "pb", 2))
		ft_push(b, a);
	if (!ft_strncmp(str, "ra", 2) || !ft_strncmp(str, "rr", 2))
		ft_rotate(a);
	if (!ft_strncmp(str, "rb", 2) || !ft_strncmp(str, "rr", 2))
		ft_rotate(b);
	if (!ft_strncmp(str, "rra", 3) || !ft_strncmp(str, "rrr", 3))
		ft_reverse_rotate(a);
	if (!ft_strncmp(str, "rrb", 3) || !ft_strncmp(str, "rrr", 3))
		ft_reverse_rotate(b);
}

void	exec_inst(t_stk **a, t_list *inst)
{
	t_stk *b;

	b = NULL;
	while (inst)
	{
		apply_inst(a, &b, inst->content);
		print_stk(*a, "a");
		print_stk(b, "b");
		printf("\n");
		inst = inst->next;
	}
	printf((!b && check_sort(*a)) ? "OK\n" : "KO\n");
	ft_stkclear(&b);
}
