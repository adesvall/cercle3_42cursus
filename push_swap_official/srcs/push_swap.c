/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:47:43 by adesvall          #+#    #+#             */
/*   Updated: 2021/09/23 15:46:48 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`

int	get_index(int *t, int n, int len)
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

void	copy_tab(int *a, int *b, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		a[i] = b[i];
		i++;
	}
}

int	*create_sorted(int *a, int len)
{
	int		i;
	int		swap;
	int		*t;

	t = malloc(len * sizeof(int));
	if (t == NULL)
		return (NULL);
	copy_tab(t, a, len);
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
	return (t);
}

void	sort_with_sorted(int *a, int len)
{
	int	*sorted;

	sorted = create_sorted(a, len);
	if (len <= 5)
		sort_5(a, len, sorted);
	else if (len <= 50)
		sort_morceaux(a, len, (len + 1) / 2, sorted);
	else if (len <= 200)
		sort_morceaux(a, len, (len + 2) / 3, sorted);
	else
		sort_morceaux(a, len, (len + 7) / 8, sorted);
	free(sorted);
}

int	main(int argc, char **argv)
{
	int	*a;

	if (argc - 1 < 1)
		return (1);
	a = argv_to_tab(argc, argv);
	if (a == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!check_sort(a, 0, argc - 1))
	{
		if (argc - 1 <= 3)
			sort_3(a, argc - 1);
		else
			sort_with_sorted(a, argc - 1);
	}
	free(a);
}
