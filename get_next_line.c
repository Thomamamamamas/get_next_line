/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:02:04 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/09 16:29:07 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUFF_SIZE
#define BUFF_SIZE 512
#endif
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	size_t		n;
	static int	first;
	static char	file[BUFF_SIZE + 2];
	char		*str;

	if (first != 1)
	{
		n = 0;
		if (fd < 0 || read(fd, file,BUFF_SIZE) < 0)
			return (NULL);
		while (file[n])
			n++;
		file[n] = '\0';
		if (file[0] == '\0')
			return (NULL);
		first = 1;
	}
	str = gnl_search(fd, file);
	return (str);
}
