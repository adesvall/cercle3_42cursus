/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:01:23 by adesvall          #+#    #+#             */
/*   Updated: 2021/09/09 13:40:11 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_exit(int code, char *str, char *str2, t_pipex *p)
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
	if (str || str2)
	{
		if (str)
			write(2, str, ft_strlen(str));
		if (str2)
		{
			write(2, ": ", 2);
			perror(str2);
		}
		else
			write(2, "\n", 1);
	}
	exit(code);
}

int	main(int argc, char **argv)
{
	extern char	**environ;
	t_pipex		p;

	ft_bzero(&p, sizeof(t_pipex));
	if (argc != 5)
		ft_exit(1, "Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2", NULL, &p);
	p.infile = argv[1];
	p.outfile = argv[4];
	p.cmd1 = ft_split(argv[2], ' ');
	if (!p.cmd1)
		ft_exit(3, "Malloc error", NULL, NULL);
	p.cmd2 = ft_split(argv[3], ' ');
	if (!p.cmd2)
		ft_exit(3, "Malloc error", NULL, &p);
	p.path = get_path(environ);
	if (!p.path)
		ft_exit(2, "Error: can't get PATH environment variable", NULL, &p);
	pipex(&p, environ);
	return (0);
}
