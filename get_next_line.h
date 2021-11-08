#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char			*get_next_line(int fd);
int				get_line_size(char *str, int start);
char			*get_line_content(char *file);

#endif
