#include "get_next_line.h"
#include <stdio.h>

int	main()
{
	int		fd;
	int		n;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	n = 0;
	while(n < 5)
	{
		line= get_next_line(fd);
		printf("%s", line);
		n++;
		free(line);
	}
	return (0);
}
