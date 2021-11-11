/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:02:04 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/11 18:21:10 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUFF_SIZE
#define BUFF_SIZE 512
#endif
#include "get_next_line.h"
#include <stdio.h>

char	*updateBuffer(char *buff, int start)
{
	int	n;

	n = 0;
	while (buff[start])
	{
		buff[n] = buff[start];
		n++;
		start++;
	}
	buff[n] = '\0';
	return (buff);
}

void	*bufferLessThanLine(char *buff, char *s1)
{
	char	*str;
	char	*s2;
	int		n;

	s2 = get_line(buff);
	n = ft_strlen_mode(s2, 1, 0);
	str = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (str);
}

char	*get_line(char *buff)
{
	int		n;
	int		len;
	char	*str;

	n = 0;
	len = ft_strlen_mode(buff, 1, 0);
	str = (char *) malloc(sizeof(char) * BUFF_SIZE + 1);
	if (!str)
		return (NULL);
	while (buff[n] && n < len)
	{
		str[n] = buff[n];
		n++;
	}
	str[n] = '\0';
	return (str);
}

char	*check_line(char *buff, int fd)
{
	int		n;
	char	*str;
	char	*tmp;

	str = get_line(buff);
	n = ft_strlen_mode(str, 0, 0);
	updateBuffer(buff, n);
	if (n == BUFF_SIZE)
	{
		while (read(fd, buff, BUFF_SIZE) != 0 && str[n - 1] != '\n')
		{
			tmp = ft_strdup(str);
			free(str);
			str = bufferLessThanLine(buff, tmp);
			free(tmp);
			n = ft_strlen_mode(str, 0, 0);
		}
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFF_SIZE + 1];
	char		*str;
	static int	read_res;

	if (!buff[0])
		read_res = read(fd, buff, BUFF_SIZE);
	if (fd < 0 || read_res < 0)
		return (NULL);
	if (read_res == 0)
	{
		return (NULL);
	}
	else
	{
		str = check_line(buff, fd);
	}
	return (str);
}
