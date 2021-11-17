/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:36:27 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/17 09:58:50 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	if (!str)
		return (0);
	while (str[n])
		n++;
	return (n);
}

char	*ft_strncpy(char *dst, char *src, size_t start, size_t size)
{
	size_t	n;
	size_t	m;

	n = start;
	m = 0;
	while (src[n] && m < size)
	{
		dst[m] = src[n];
		n++;
		m++;
	}
	dst[m] = '\0';
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	n;
	size_t	m;
	char *str;

	if(!s1 && !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
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

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen(s);
	res = (char *) malloc(sizeof(*s) * len + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	m;

	m = 0;
	while (m < n)
	{
		*((unsigned char *)s + m) = (unsigned char)c;
		m++;
	}
	return (s);
}
