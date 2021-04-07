/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 19:21:28 by adesvall          #+#    #+#             */
/*   Updated: 2021/04/07 18:54:15 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prout.h"

void	copy_tab(int *a, int *b, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		a[i] = b[i];
		i++;
	}
}

void	print_tab(int *a, int sep, int len)
{
	int i;

	printf("Stack status :\n");
	i = 0;
	while (i < len)
	{
		if (i == sep)
			printf("-\n");
		printf("%d\n", a[i]);
		i++;
	}
}

int 	get_index(int *t, int n, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (t[i] == n)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}

void	sort_tab(int *t, int len)
{
	int		i;
	int		swap;

	i = 0;
	while (i < len - 1)
	{
		if (t[i] > t[i + 1])
		{
			swap = t[i];
			t[i] = t[i + 1];
			t[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
}

int		abs(int	n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int 	min(int a, int b, int c)
{
	int min;

	if (a < b)
		min = a;
	else
		min = b;
	if (c < min)
		min = c;
	return (min);
}

int 	dist(int *t, int *a, int sep, int len)
{
	int i;
	int	dist;
	int target;

	dist = 0;
	i = 0;
	while (i < len)
	{
		target = get_index(t, a[i], len);
		dist += min(abs(i - target) + (((sep - i) * (sep - target) >= 0) ? 0 : 1),
				abs(i - sep) + (len - target) + 1,
				(len - i) + target + 1);
		i++;
	}
	return (dist);
}

void	save_res(int *a, int sep, t_info *info, int step)
{
	int		i;

	// copy inst
	i = 0;
	while (i < step)
	{
		info->inst_res[info->step_res + i] = info->inst[i];
		i++;
	}
	// copy tab
	i = 0;
	while (i < info->len)
	{
		info->tab_res[i] = a[i];
		i++;
	}
	info->sep_res = sep;
}

int	solve_inst(int *a, int sep, int step, t_info *info, int maxstep)
{
	int i;
	int	distance;
	int g;

	if (check_sort(a, sep, info->len))
	{
		save_res(a, sep, info, step);
		return (1);
	}
	if (step >= maxstep)
	{
		if (maxstep < MAX_LEAP - 1)
			return (0);
		distance = dist(info->sorted, a, sep, info->len);
		if (distance < info->best_dist)
		{
			save_res(a, sep, info, step);
			info->best_dist = distance;
		}
		return (0);
	}
	i = 0;
	while (i < 8)
	{
		if (step && !ft_strcmp(info->invl[i], info->inst[step - 1]))
		{
			i++;
			continue;
		}
		g = (i < 6) ? info->fonct[i](a, sep, info->len) : info->fonct[i](&sep, info->len);
		if (g)
		{
			info->inst[step] = info->list[i];
			if (solve_inst(a, sep, step + 1, info, maxstep))
				return (1);
			info->inst[step] = NULL;
			if (i < 6)
				info->invf[i](a, sep, info->len);
			else
				info->invf[i](&sep, info->len);
		}
		i++;
	}
	return (0);
}

#define LEN 8

int	main(int argc, char **argv)
{
	int a[LEN] = {5, 3, 2, 8, 6, 4, 7, 1};
	t_info	info;

	info.len = LEN;
	info.tab_res = malloc(info.len * sizeof(int));
	info.step_res = 0;
	info.sep_res = 0;
	info.sorted = (int[8]){1,2,3,4,5,6,7,8};

	info.fonct = (int (*[8])()){ft_swap_a, ft_swap_b, ft_rotate_a, ft_rotate_b, ft_reverse_rotate_a, ft_reverse_rotate_b, ft_push_a, ft_push_b};
	info.invf = (int (*[8])()){ft_swap_a, ft_swap_b, ft_reverse_rotate_a, ft_reverse_rotate_b, ft_rotate_a, ft_rotate_b, ft_push_b, ft_push_a};
	info.list = (char*[8]){"sa", "sb", "ra", "rb", "rra", "rrb", "pa", "pb"};
	info.invl = (char*[8]){"sa", "sb", "rra", "rrb", "ra", "rb", "pb", "pa"};
	
	info.inst = malloc(100 * sizeof(char*));
	info.inst_res = malloc(100 * sizeof(char*));
	for (int i=0; i<100; i++)
	{
		info.inst[i] = 0;
		info.inst_res[i] = 0;
	}

	int is_sorted = 0;
	while (!is_sorted)
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
		int i =-1;
		while (++i < info.step_res)
			printf("%d : %s\n", i, info.inst_res[i]);
		print_tab(info.tab_res, info.sep_res, info.len);
	}

	
	free(info.inst);
	free(info.inst_res);
	free(info.tab_res);
}