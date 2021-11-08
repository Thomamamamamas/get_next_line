/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:02:04 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/08 16:45:12 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef BUFF_SIZE
#define BUFF_SIZE 512
#endif
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static int	first;
	static char	*file;
	char		*str;

	if (first != 1)
	{
		file = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
		if (fd < 0 || !file || read(fd, file,BUFF_SIZE) < 0)
		{
			printf("Erreur, read renvoie : %zd\n", read(fd, file, BUFF_SIZE));
			return (NULL);
		}
		first = 1;
		file[BUFF_SIZE + 1] = '\0';
	}
	str = get_line_content(file);
	return (str);
}
