/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:10:21 by adesvall          #+#    #+#             */
/*   Updated: 2021/09/09 13:12:00 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft.h"

typedef struct s_pipex
{
	char	*path;
	char	*infile;
	char	*outfile;
	char	**cmd1;
	char	**cmd2;
	char	*path1;
	char	*path2;
}				t_pipex;

void	pipex(t_pipex *p, char **env);
int		ft_exit(int code, char *str, char *str2, t_pipex *p);
char	*get_path(char **env);
char	*parse_path(char *path, char *cmd);

#endif