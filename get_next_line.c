/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:02:04 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/17 10:59:46 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUFF_SIZE
#define BUFF_SIZE 512
#endif
#include "get_next_line.h"
#include <stdio.h>


size_t	linelen(char *buff, size_t start)
{
	size_t	len;

	len = start + 1;
	while (buff[len] && buff[len - 1] != '\n')
		len++;
	return (len - start);
}

char	*linecpy(char *buff, size_t start)
{
	size_t	len;
	char	*line;

	len = linelen(buff, start);
	line = (char *)malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	ft_strncpy(line, buff, start, len);
	return (line);
}

char	*linecomplete(char *buff, char *line, size_t len, int fd)
{
	char	*newLine;
	char	*tmp;

	while (read(fd, buff, BUFF_SIZE) > 0 && line[len] != '\n')
	{
		tmp = linecpy(buff, 0);
		newLine = ft_strjoin(line, tmp);
		free(tmp);
		free(line);
		line = ft_strdup(newLine);
		len = ft_strlen(line);
		free(newLine);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char			buff[BUFF_SIZE + 1];
	static size_t		len;
	static size_t		first;
	char				*line;

	if (first != 1)
	{
		first = 1;
		len = 0;
		if (fd < 0 || read(fd, buff, BUFF_SIZE) <= 0)
			return (NULL);
	}
	line = linecpy(buff, len);
	len = len + ft_strlen(line);
	if (len == BUFF_SIZE && line[len] != '\n')
	{
		line = linecomplete(buff, line, len, fd);
		len = ft_strlen(line);
		first = 0;
	}
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
