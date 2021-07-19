/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:01:31 by adesvall          #+#    #+#             */
/*   Updated: 2021/07/19 16:57:51 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		inputfile(int fdpid, char *path, t_pipex *p, char **env)
{
	int		fd;

	fd = open(p->infile, O_RDONLY);
	if (fd == -1)
		ft_exit(-2, "Can't read file 1.\n");
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdpid, STDOUT_FILENO);
	close(fdpid);
	if (execve(path, p->cmd1, env) == -1)
		ft_exit(-3, "ERROR: can't apply first command.\n");
	return (0);
}

int		outputfile(int fdpid, char *path, t_pipex *p, char **env)
{
	int		fd;

	fd = open(p->outfile, O_WRONLY);
	if (fd == -1)
		ft_exit(-2, "Can't read file 2.\n");
	dup2(fdpid, STDIN_FILENO);
	close(fdpid);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (execve(path, p->cmd1, env) == -1)
		ft_exit(-3, "ERROR: can't apply first command.\n");
	return (0);
}

void    pipex(t_pipex *p, char **env)
{
	pid_t	pid;
	int		pipefd[2];
	char	*curr;

	if (pipe(pipefd))
		ft_exit(-4, "ERROR: can't create pipe");
	pid = fork();
	if (pid == 0)
	{
		close(pipefd[0]);
		curr = parse_path(p->path, p->cmd1[0]);
		if (!curr)
			ft_exit(-5, "ERROR: incorrect command.\n");
		inputfile(pipefd[1], curr, p, env);
		free(curr);
	}
	else
	{
		close(pipefd[1]);
		curr = parse_path(p->path, p->cmd2[0]);
		if (!curr)
			ft_exit(-5, "ERROR: incorrect command.\n");
		outputfile(pipefd[0], curr, p, env);
		free(curr);
	}
}

// https://github.com/SashaPo/Pipex