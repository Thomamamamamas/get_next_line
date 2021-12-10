#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define FD_MAX 256

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*trimline(char *save);
char	*restline(char *save);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
