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

int		main(int argc, char **argv)
{
	int		*a;

	if (argc == 1)
		return (1);
	if (!(a = argv_to_tab(argc, argv)))
	{
		printf("Error\n");
		return (1);
	}
	print_tab(a, 0, argc-1);
	return (0);
}