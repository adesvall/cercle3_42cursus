/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:47:43 by adesvall          #+#    #+#             */
/*   Updated: 2021/05/16 15:15:31 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_info	info;
	int		*a;

	if (argc == 1)
		return (1);
	a = argv_to_tab(argc, argv);
	if (a == NULL)
	{
		printf("Error\n");
		return (1);
	}
	print_tab(a, 0, argc - 1);

	info.len = argc - 1;
	info.tab_res = malloc(info.len * sizeof(int));
	info.step_res = 0;
	info.sep_res = 0;
	
	info.fonct = (int (*[8])()){ft_swap_a, ft_swap_b, ft_rotate_a, ft_rotate_b, ft_reverse_rotate_a, ft_reverse_rotate_b, ft_push_a, ft_push_b};
	info.invf = (int (*[8])()){ft_swap_a, ft_swap_b, ft_reverse_rotate_a, ft_reverse_rotate_b, ft_rotate_a, ft_rotate_b, ft_push_b, ft_push_a};
	
	info.list = (char*[8]){"sa", "sb", "ra", "rb", "rra", "rrb", "pa", "pb"};
	info.invl = (char*[8]){info.list[0], info.list[1], info.list[4], info.list[5], info.list[2], info.list[3], info.list[7], info.list[6]};
	info.special = (char*[3]){"ss", "rr", "rrr"};
	info.invspecial = (char*[3]){info.special[0], info.special[2], info.special[1]};
	
	info.inst = malloc(100 * sizeof(char*));
	info.inst_res = malloc(100 * sizeof(char*));
	for (int i=0; i<100; i++)
	{
		info.inst[i] = 0;
		info.inst_res[i] = 0;
	}

	int original_dist = insert_sort(a, 0, info.len);

	int is_sorted = 0;
	while (!is_sorted && info.step_res < 50)
	{
		int maxstep = 1;
		while (maxstep < MAX_LEAP && !is_sorted)
		{
			info.best_dist = __INT32_MAX__;
			is_sorted = solve_inst(a, info.sep_res, 0, &info, maxstep);
			// printf("NOTHING FOR %d\n", maxstep);
			maxstep++;
		}
		printf("--- %d += %d ---\n", info.step_res, maxstep-1);
		info.step_res += maxstep-1;
		copy_tab(a, info.tab_res, info.len);
		print_tab(info.tab_res, info.sep_res, info.len);
	}
	int i = 0;
	while (i < info.step_res)
	{
		printf("%d : %s\n", i, info.inst_res[i]);
		i++;
	}
	printf("original dist : %d\n", original_dist);
	
	free(info.inst);
	free(info.inst_res);
	free(a);
	free(info.tab_res);
}
