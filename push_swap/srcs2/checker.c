/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:52:54 by adesvall          #+#    #+#             */
/*   Updated: 2021/03/13 19:25:59 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_inst(t_list *inst)
{
	printf("inst :\n");
	while (inst)
	{
		printf("-%s\n", (char*)inst->content);
		inst = inst->next;
	}
}

int		is_instruction(char *str)
{
	if (!ft_strncmp(str, "sa", 2))
		return (1);
	else if (!ft_strncmp(str, "sb", 2))
		return (1);
	else if (!ft_strncmp(str, "ss", 2))
		return (1);
	else if (!ft_strncmp(str, "pa", 2))
		return (1);
	else if (!ft_strncmp(str, "pb", 2))
		return (1);
	else if (!ft_strncmp(str, "ra", 2))
		return (1);
	else if (!ft_strncmp(str, "rb", 2))
		return (1);
	else if (!ft_strncmp(str, "rr", 2))
		return (1);
	else if (!ft_strncmp(str, "rra", 3))
		return (1);
	else if (!ft_strncmp(str, "rrb", 3))
		return (1);
	else if (!ft_strncmp(str, "rrr", 3))
		return (1);
	return (0);
}

s

int		main(int argc, char **argv)
{
	t_list	*inst;
	t_stk	*a;

	if (argc == 1)
		return (1);
	if (!(a = argv_to_stk(argc, argv)))
	{
		printf("Error\n");
		return (1);
	}
	print_stk(a, "a");
	inst = read_instructions();
	if (!inst)
		printf("Error\n");
	exec_inst(&a, inst);
	ft_stkclear(&a);
	ft_lstclear(&inst, free);
	return (0);
}
