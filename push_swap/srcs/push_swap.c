/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:47:43 by adesvall          #+#    #+#             */
/*   Updated: 2021/03/14 19:21:07 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	fill_targets(t_stk *a)
{
	int		*tab;
	int		len;
	int		i;
	t_stk	*cur;

	len = ft_stklen(a);
	tab = malloc(len * sizeof(int));
	cur = a;
	i = 0;
	while (cur)
	{
		tab[i++] = cur->content;
		cur = cur->next;
	}
	sort_tab(tab, len);
	cur = a;
	while (cur)
	{
		cur->target = get_index(tab, cur->content, len);
		cur = cur->next;
	}
	free(tab);
}

void	find_inst_a(t_stk **a, t_stk **b)
{
	while (!checksort(*a))
	{
		if ((*a)->content < (*a)->next->content && (*a)->content < ft_stkget_last(*a)->content)
		{}
	}
}

void	solve_stk(t_stk *a)
{
	t_stk	*b;
	t_stk	*last;

	b = NULL;
	fill_targets(a);
	while (!b || !check_sort(a))
	{
		
		if (a->target <= ft_stklen(b) + 1)
		{
			ft_push(&b, &a);
			printf("pb\n");
		}
		else
		{
			last = ft_stkget_last(a);
			if (last->target <= ft_stklen(b))
			{
				ft_reverse_rotate(&a);
				printf("rra\n");
			}
			else if (a->target >= ft_stklen(b) + ft_stklen(a) / 2)
			{
				ft_rotate(&a);
				printf("ra\n");
			}
			else
			{
				ft_swap(a);
				printf("sa\n");
			}
		}
	}
	ft_stkclear(&a);
}

int		main(int argc, char **argv)
{
	t_stk	*a;

	if (argc == 1)
		return (1);
	if (!(a = argv_to_stk(argc, argv)))
	{
		printf("Error\n");
		return (1);
	}
	print_stk(a, "a");
	solve_stk(a);
	return (0);
}