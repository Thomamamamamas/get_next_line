#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t			ft_strlen_mode(const char *str, int mode, int start);
char			*ft_strjoin(char const *s1, char const *s2);
char			*gnl_content(int fd, char *file, size_t n, int size);
char			*gnl_search(int fd, char *file);
char			*get_next_line(int fd);

#endif
