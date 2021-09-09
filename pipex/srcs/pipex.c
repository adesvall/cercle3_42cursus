/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:01:31 by adesvall          #+#    #+#             */
/*   Updated: 2021/09/09 15:39:05 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	inputfile(int fdpipe, t_pipex *p, char **env)
{
	int		fd;

	fd = open(p->infile, O_RDONLY);
	if (fd == -1)
		ft_exit(errno, p->infile, "can't open file", p);
	p->path1 = parse_path(p->path, p->cmd1[0]);
	if (!p->path1)
		ft_exit(0, p->cmd1[0], "command not found", p);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdpipe, STDOUT_FILENO);
	close(fdpipe);
	if (execve(p->path1, p->cmd1, env) == -1)
		ft_exit(errno, "can't execute command", p->cmd1[0], p);
}

void	outputfile(int fdpipe, t_pipex *p, char **env)
{
	int		fd;

	unlink(p->outfile);
	fd = open(p->outfile, O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		ft_exit(1, p->outfile, "can't create file", p);
	p->path2 = parse_path(p->path, p->cmd2[0]);
	if (!p->path2)
		ft_exit(127, p->cmd2[0], "command not found", p);
	dup2(fdpipe, STDIN_FILENO);
	close(fdpipe);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	if (execve(p->path2, p->cmd2, env) == -1)
		ft_exit(errno, "can't execute command", p->cmd2[0], p);
}

void	launch_programs(t_pipex *p, int *pipefd, char **env)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_exit(errno, "Error", "fork", p);
	if (pid == 0)
	{
		close(pipefd[0]);
		inputfile(pipefd[1], p, env);
	}
	else
	{
		close(pipefd[1]);
		outputfile(pipefd[0], p, env);
	}
}

void	pipex(t_pipex *p, char **env)
{
	pid_t	pid;
	int		pipefd[2];
	int		status;

	if (pipe(pipefd))
		ft_exit(errno, "Error", "pipe", p);
	pid = fork();
	if (pid == -1)
		ft_exit(errno, "Error", "fork", p);
	if (pid == 0)
		launch_programs(p, pipefd, env);
	else
	{
		close(pipefd[0]);
		close(pipefd[1]);
		wait(&status);
	}
	ft_exit(status, NULL, NULL, p);
}
