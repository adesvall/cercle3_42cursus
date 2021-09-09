/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:01:37 by adesvall          #+#    #+#             */
/*   Updated: 2021/09/09 13:41:21 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			return (env[i] + 5);
		i++;
	}
	return (NULL);
}

char	*find_access(char **dir, char *cmd)
{
	int		i;
	char	*curr;

	i = 0;
	while (dir[i])
	{
		curr = ft_strjoin(dir[i], cmd);
		if (!access(curr, F_OK))
		{
			free(cmd);
			ft_abort(dir);
			return (curr);
		}
		free(curr);
		i++;
	}
	free(cmd);
	ft_abort(dir);
	return (NULL);
}

char	*parse_path(char *path, char *cmd)
{
	char	**dir;
	char	*tmp;

	if (!access(cmd, F_OK))
		return (ft_strjoin("", cmd));
	tmp = ft_strjoin("/", cmd);
	if (!tmp)
		return (NULL);
	dir = ft_split(path, ':');
	if (!dir)
	{
		free(tmp);
		return (NULL);
	}
	return (find_access(dir, tmp));
}
