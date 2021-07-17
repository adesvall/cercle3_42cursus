


#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include "libft.h"

typedef struct s_pipex
{
    char *path;
    char *infile;
    char **cmd1;
    char **cmd2;
    char *outfile;
}               t_pipex;

#endif