

#include "pipex.h"

int ft_exit(int code, char *str)
{
	printf("%s\n", str);
	exit(code);
}

int	main(int argc, char **argv)
{
	extern char	**environ;
	t_pipex		p;

	if (argc != 5)
		ft_exit(-1, "Usage: ./pipex file1 cmd1 cmd2 file2");
	p.infile = argv[1];
	p.outfile = argv[4];
	p.path = get_path(environ);
	if (!p.path)
		ft_exit(-1, "error: can't get PATH environment variable");
	signal(SIGPIPE, SIG_IGN);
}