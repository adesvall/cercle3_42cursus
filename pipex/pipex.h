


#ifndef PIPEX_H
#define PIPEX_H

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
//#include "libft.h"

typedef struct s_pipex
{
    char *path;
    char *infile;
    char **cmd1;
    char **cmd2;
    char *outfile;
}               t_pipex;

int     ft_exit(int code, char *str);
char    *get_path(char **env);

#endif