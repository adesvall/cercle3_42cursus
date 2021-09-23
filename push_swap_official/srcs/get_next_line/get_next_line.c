/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adesvall <adesvall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 02:38:25 by adesvall          #+#    #+#             */
/*   Updated: 2021/06/26 16:03:44 by adesvall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*trimstart(char *ligne)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	if (!ligne)
		return (0);
	while (ligne[i] && ligne[i] != '\n')
		i++;
	if (!ligne[i])
	{
		free(ligne);
		return (0);
	}
	res = malloc(sizeof(char) * ((ft_strlen(ligne) - i) + 1));
	if (!res)
		return (0);
	i++;
	j = 0;
	while (ligne[i])
		res[j++] = ligne[i++];
	res[j] = '\0';
	free(ligne);
	return (res);
}

char	*trimend(char *str)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	rtn = malloc(sizeof(char) * (i + 1));
	if (!rtn)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		rtn[i] = str[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

int	read_line(char **ligne, int fd)
{
	char	*buf;
	int		resread;

	resread = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	while (!is_endofline(*ligne) && resread == 1)
	{
		resread = read(fd, buf, BUFFER_SIZE);
		if (resread != -1)
			buf[resread] = '\0';
		if (resread != -1)
			*ligne = join_and_realloc(*ligne, buf);
	}
	free(buf);
	return (resread);
}

int	get_next_line(int fd, char **line)
{
	int			resread;
	static char	*ligne;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	resread = read_line(&ligne, fd);
	*line = trimend(ligne);
	ligne = trimstart(ligne);
	if (resread > 0 || is_endofline(ligne))
		return (1);
	free(ligne);
	ligne = NULL;
	return (resread);
}
