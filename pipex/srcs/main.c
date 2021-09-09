/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:01:23 by adesvall          #+#    #+#             */
/*   Updated: 2021/09/09 16:19:38 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*format_error(char *str2)
{
	char	*res;

	res = ft_strjoin(": ", str2);
	str2 = ft_strjoin(res, ": ");
	free(res);
	res = ft_strjoin(str2, strerror(errno));
	free(str2);
	return (res);
}

void	print_error(char *str, char *str2)
{
	char	*msg;

	msg = "";
	if (str || str2)
	{
		if (str)
			msg = str;
		if (str2)
		{
			str = format_error(str2);
			msg = ft_strjoin(msg, str);
			free(str);
		}
		str = ft_strjoin(msg, "\n");
		if (str2)
			free(msg);
		write(2, str, ft_strlen(str));
		free(str);
	}
}

int	ft_exit(int code, char *str, char *str2, t_pipex *p)
{
	print_error(str, str2);
	if (p)
	{
		if (p->cmd1)
			ft_abort(p->cmd1);
		if (p->cmd2)
			ft_abort(p->cmd2);
		free(p->path1);
		free(p->path2);
	}
	exit(code);
}

int	main(int argc, char **argv)
{
	extern char	**environ;
	t_pipex		p;

	ft_bzero(&p, sizeof(t_pipex));
	if (argc != 5)
		ft_exit(1, "Usage: ./pipex file1 \"cmd1\" \"cmd2\" file2", NULL, NULL);
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
