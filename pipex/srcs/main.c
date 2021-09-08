/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:01:23 by adesvall          #+#    #+#             */
/*   Updated: 2021/09/08 16:45:35 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int ft_exit(int code, char *str, t_pipex *p)
{
	if (p)
	{
		if (p->cmd1)
			ft_abort(p->cmd1);
		if (p->cmd2)
			ft_abort(p->cmd2);
		free(p->path1);
		free(p->path2);
	}
	if (str)
	{
		printf("%s\n", str);
		perror(str);
	}
	exit(code);
}

int	main(int argc, char **argv)
{
	extern char	**environ;
	t_pipex		p;

	ft_bzero(&p, sizeof(t_pipex));
	if (argc != 5)
		ft_exit(1, "Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2", &p);
	p.infile = argv[1];
	p.outfile = argv[4];
	p.cmd1 = ft_split(argv[2], ' ');
	p.cmd2 = ft_split(argv[3], ' ');
	p.path = get_path(environ);
	if (!p.path)
		ft_exit(2, "ERROR: can't get PATH environment variable", &p);
	pipex(&p, environ);
	return 0;
}
