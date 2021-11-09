/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:36:27 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/09 16:29:05 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen_mode(const char *str, int mode, int start)
{
	size_t	n;

	if (mode == 0)
	{
		n = 0;
		while (str[n])
			n++;
	}
	else
	{
		n = start;

		while (str[n] != '\n' && str[n])
			n++;
		n = n - start + 1;
	}
	return (n);
}

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	size_t	m;
	char *str;

	if(!s1 && !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen_mode(s1, 0, 0) + ft_strlen_mode(s2, 0, 0) + 1));
	if (!str)
		return (NULL);
	n = 0;
	m = 0;
	while (s1[m])
	{
		str[n] = s1[m];
		m++;
		n++;
	}
	m = 0;
	while (s2[m])
	{
		str[n] = s2[m];
		m++;
		n++;
	}
	str[n] = '\0';
	return (str);
}

char	*gnl_content(int fd, char *file, size_t n, int size)
{
	char		*s1;
	size_t		m;

	s1 = (char *)malloc(sizeof(char) * size + 1);
	m = 0;
	while (m < size && file[n] && s1[m])
	{
		s1[m] = file[n];
		m++;
		n++;
	}
	s1[m] = '\0';
	printf("%s\n", s1);
	return (s1);
}

char	*gnl_search(int fd, char *file)
{
	static int		first;
	static size_t	n;
	size_t			size;
	char			*s1;
	char			*s2;
	if (first != 1)
	{
		n = 0;
		first = 1;
	}
	size = ft_strlen_mode(file, 1, n);
	s1 = gnl_content(fd, file, n, size);
	n = n + size;
	return (s1);
}
