
#include "pipex.h"

char    *get_path(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
		if (!ft_strcmp(env[i], "PATH"))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

