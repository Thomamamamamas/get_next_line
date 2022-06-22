/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcasale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 16:53:36 by tcasale           #+#    #+#             */
/*   Updated: 2022/06/22 16:53:39 by tcasale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_trimline(char *save);
char	*gnl_restline(char *save);
char	*gnl_ft_strchr(char *s, int c);
size_t	gnl_ft_strlen(char *s);
char	*gnl_ft_strjoin(char *s1, char *s2);

#endif
