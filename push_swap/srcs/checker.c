/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 17:52:54 by adesvall          #+#    #+#             */
/*   Updated: 2021/03/12 16:51:32 by adesvall         ###   ########.fr       */
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

t_list	*read_instructions(void)
{
	t_list	*inst;
	char	*line;
	int		gnl;

	inst = NULL;
	gnl = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(0, &line);
		ft_lstadd_back(&inst, ft_lstnew(line));
		if (line[0] && !is_instruction(line))
		{
			ft_lstclear(&inst, free);
			return (NULL);
		}
	}
	return (inst);
}

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
