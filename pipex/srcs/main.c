/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:01:23 by adesvall          #+#    #+#             */
/*   Updated: 2021/07/20 11:59:22 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_exit(int code, char *str, t_pipex *p)
{
	ft_abort(p->cmd1);
	ft_abort(p->cmd2);
	printf("%s\n", str);
	exit(code);
}

int	main(int argc, char **argv)
{
	extern char	**environ;
	t_pipex		p;

	if (argc != 5)
		ft_exit(-1, "Usage: ./pipex file1 cmd1 cmd2 file2", &p);
	p.infile = argv[1];
	p.outfile = argv[4];
	p.cmd1 = ft_split(argv[2], ' ');
	p.cmd2 = ft_split(argv[3], ' ');
	p.path = get_path(environ);
	if (!p.path)
		ft_exit(-1, "ERROR: can't get PATH environment variable", &p);
	pipex(&p, environ);
	ft_exit(0, "", &p);
}