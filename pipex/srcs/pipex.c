/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:01:31 by adesvall          #+#    #+#             */
/*   Updated: 2021/09/06 23:22:55 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int		inputfile(int fdpid, char *path, t_pipex *p, char **env)
{
	int		fd;

	fd = open(p->infile, O_RDONLY);
	if (fd == -1)
		ft_exit(-2, "ERROR: Can't open file 1.", p);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdpid, STDOUT_FILENO);
	close(fdpid);
	if (execve(path, p->cmd1, env) == -1)
		ft_exit(-3, "ERROR: can't apply first command.", p);
	return (0);
}

int		outputfile(int fdpid, char *path, t_pipex *p, char **env)
{
	int		fd;

	unlink(p->outfile);
	fd = open(p->outfile, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		ft_exit(-2, "ERROR: Can't open file 2.", p);
	dup2(fdpid, STDIN_FILENO);
	close(fdpid);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (execve(path, p->cmd2, env) == -1)
		ft_exit(-3, "ERROR: Can't apply second command.", p);
	return (0);
}

int    pipex(t_pipex *p, char **env)
{
	pid_t	pid;
	pid_t	pid2;
	int		pipefd[2];
	char	*curr;

	if (pipe(pipefd))
		ft_exit(errno, "ERROR: can't create pipe", p);
	pid = fork();
	if (pid == 0)
	{
		pid2 = fork();
		if (pid2 == 0)
		{
			curr = parse_path(p->path, p->cmd2[0]);
			if (!curr)
				ft_exit(6, "ERROR: incorrect command.", p);
			outputfile(pipefd[0], curr, p, env);
			free(curr);
		}
		else if (pid2 > 0)
		{
			curr = parse_path(p->path, p->cmd1[0]);
			if (!curr)
				ft_exit(6, "ERROR: incorrect command.", p);
			inputfile(pipefd[1], curr, p, env);
			free(curr);
		}
	}
	else
		wait(NULL);
	ft_exit(0, NULL, p);
	return (0);
}

// https://github.com/SashaPo/Pipex
