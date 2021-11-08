/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:36:27 by tcasale           #+#    #+#             */
/*   Updated: 2021/11/08 16:45:09 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_line_size(char *str, int start)
{
	int	n;

	n = start;

	while(str[n] != '\n' && str[n])
		n++;
	n = n - start + 1;
	return (n);
}

char	*get_line_content(char *file)
{
	static int	n;
	static int	first;
	int			m;
	int			size;
	char		*str;
	if (first != 1)
	{
		n = 0;
		first = 1;
	}
	size = get_line_size(file, n);
	str = (char *)malloc(sizeof(char) * size + 1);
	m = 0;
	while (m < size && file[n])
	{
		str[m] = file[n];
		m++;
		n++;
	}
	str[m] = '\0';
	return (str);
}
