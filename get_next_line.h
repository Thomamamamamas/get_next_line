#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char			*get_next_line(int fd);
size_t			linelen(char *buff, size_t start);
char			*linecpy(char *buff, size_t start);
char			*linecomplete(char *buff, char *line, size_t len, int fd);
size_t			ft_strlen(const char *str);
char			*ft_strncpy(char *dst, char *src, size_t start, size_t size);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strdup(const char *s);
void			*ft_memset(void *s, int c, size_t n);

#endif
