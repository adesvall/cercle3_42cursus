/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:01:37 by adesvall          #+#    #+#             */
/*   Updated: 2021/07/19 17:04:35 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *get_path(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char		*parse_path(char *path, char *cmd)
{
	char	**dir;
	char	*curr;
	char	*tmp;
	int		i;

	dir = ft_split(path, ':');
	i = 0;
	while (dir[i])
	{
		if (cmd[0] != '/')
			tmp = ft_strjoin(dir[i], "/");
		free(dir[i]);
		dir[i] = tmp;
		curr = ft_strjoin(dir[i], cmd);
		if (!access(curr, F_OK))
		{
			ft_abort(dir);
			return (curr);
		}
		i++;
	}
	return (NULL);
}
