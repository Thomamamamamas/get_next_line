#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		fd;
	int		n;
	char	*line;

	fd = open("test.txt", O_RDWR);
	n = 0;
	while(n < 1)
	{
		line= get_next_line(fd);
		printf("%s", line);
		n++;
	}
	return (0);
}
