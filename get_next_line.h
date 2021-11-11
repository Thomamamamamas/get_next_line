#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char			*updateBuffer(char *buff, int start);
void			*bufferLessThanLine(char *buff, char *str);
char			*get_line(char *buff);
char			*get_next_line(int fd);
size_t			ft_strlen_mode(const char *str, int mode, int start);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s);

#endif
