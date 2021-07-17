
#include "pipex.h"

int		inputfile(int fdpid, char *path, t_pip *p, char **env)
{
	int		fd;

	if ((fd = open(p->file1, O_RDONLY)) == -1)
		ft_panic("Can't read file.\n");
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(fdpid, STDOUT_FILENO);
	close(fdpid);
	if (execve(path, p->cmd1, env) == -1)
		ft_panic("ERROR: can't apply first command.\n");
	return (0);
}

void    pipex(t_pipex p, char **env)
{
	pid_t	pid;
	int		pipefd[2];
	char	*curr;

	if (pipe(pipefd))

}

https://github.com/SashaPo/Pipex