/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 17:47:43 by adesvall          #+#    #+#             */
/*   Updated: 2021/06/17 00:31:17 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ARG=`ruby -e "puts (0..100).to_a.shuffle.join(' ')"`

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

int *create_sorted(int *a, int len)
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

int	main(int argc, char **argv)
{
	int		*a;
	int		*sorted;

	if (argc - 1 < 2)
		return (1);
	a = argv_to_tab(argc, argv);
	if (a == NULL)
	{
		printf("Error\n");
		return (1);
	}
	// print_tab(a, 0, argc - 1);
	if (argc - 1 <= 3)
		sort_3(a, argc - 1);
	else
	{
		sorted = create_sorted(a, argc - 1);
		if (argc - 1 <= 5)
			sort_5(a, argc - 1, sorted);
		else if (argc - 1 <= 100)
			sort_morceaux(a, argc - 1, 4, sorted);
		else
			sort_morceaux(a, argc - 1, 10, sorted);
		free(sorted);
	}
	free(a);
}
