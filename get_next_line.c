/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdionisi <mdionisi@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:03:14 by mdionisi          #+#    #+#             */
/*   Updated: 2022/09/19 17:37:36 by mdionisi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#define BUFFER_SIZE 42

static	char	*read_line(int fd, char *backup)
{
	int		bytes;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes > 0 && !ft_strchr(backup, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		backup = ft_strjoin(backup, buff);
	}
	free(buff);
	return (backup);
}

static	char	*cut_read(char *backup)
{
	char	*line;
	int		i;

	if (!*backup)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static	char	*rest(char *backup)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	if (!backup[i])
	{
		free(backup);
		return (NULL);
	}
	if (backup[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (backup[i] != '\0')
		line[j++] = backup[i++];
	line[j] = '\0';
	free(backup);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_line(fd, backup);
	if (!backup)
		return (NULL);
	line = cut_read(backup);
	backup = rest(backup);
	return (line);
}
