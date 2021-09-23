/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:47:35 by adesvall          #+#    #+#             */
/*   Updated: 2021/06/18 12:57:37 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	apply_inst(const char *inst, int *a, int *sep, int len)
{
	if (!ft_strcmp(inst, "sa") || !ft_strcmp(inst, "ss"))
		ft_swap_a(a, *sep, len, 0);
	else if (!ft_strcmp(inst, "sb") || !ft_strcmp(inst, "ss"))
		ft_swap_b(a, *sep, len, 0);
	else if (!ft_strcmp(inst, "ra") || !ft_strcmp(inst, "rr"))
		ft_rotate_a(a, *sep, len, 0);
	else if (!ft_strcmp(inst, "rb") || !ft_strcmp(inst, "rr"))
		ft_rotate_b(a, *sep, len, 0);
	else if (!ft_strcmp(inst, "rra") || !ft_strcmp(inst, "rrr"))
		ft_reverse_rotate_a(a, *sep, len, 0);
	else if (!ft_strcmp(inst, "rrb") || !ft_strcmp(inst, "rrr"))
		ft_reverse_rotate_b(a, *sep, len, 0);
	else if (!ft_strcmp(inst, "pa"))
		ft_push_a(sep, len, 0);
	else if (!ft_strcmp(inst, "pb"))
		ft_push_b(sep, len, 0);
	else
		return (0);
	return (1);
}

void	read_and_apply_insts(int *a, int len)
{
	char	*line;
	int		gnl;
	int		sep;
	int		err;

	err = 0;
	sep = 0;
	gnl = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(0, &line);
		if (line[0] && !apply_inst(line, a, &sep, len))
			err = 1;
		free(line);
	}
	if (err)
		write(2, "Error\n", 6);
	else if (check_sort(a, sep, len))
		printf("OK\n");
	else
		printf("KO\n");
}

int	main(int argc, char **argv)
{
	int	*a;

	if (argc - 1 < 2)
		return (1);
	a = argv_to_tab(argc, argv);
	if (a == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	read_and_apply_insts(a, argc - 1);
	free(a);
}
