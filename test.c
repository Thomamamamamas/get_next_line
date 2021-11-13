#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		fd;
	int		n;
	char	*line;

	fd = open("42_with_nl.txt", O_RDWR);
	n = 0;
	while (n < 5)
	{
		line= get_next_line(fd);
		printf("ligne %d = %s", n, line);
		n++;
	}
	return (0);
}
