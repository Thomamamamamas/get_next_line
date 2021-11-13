/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:36:27 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/13 17:24:38 by tcasale          ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
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

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len;
	int		i;

	len = ft_strlen_mode(s, 0, 0);
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
