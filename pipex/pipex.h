


#ifndef PIPEX_H
#define PIPEX_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include "libft.h"

typedef struct s_pipex
{
    char *path;
    char *infile;
    char **cmd1;
    char **cmd2;
    char *outfile;
}               t_pipex;

int    pipex(t_pipex *p, char **env);
int     ft_exit(int code, char *str, t_pipex *p);
char    *get_path(char **env);
char	*parse_path(char *path, char *cmd);

#endif