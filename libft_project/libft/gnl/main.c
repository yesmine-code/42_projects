#include "get_next_line.h"


#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>

int main()
{
	char	**line;
	int		fd;

	line = malloc(1);
	fd = open("one_big_fat_line.txt", O_RDONLY);
	//fd = open("test.txt", O_RDONLY);
	while (get_next_line(fd, line))
		printf("%s", *line);
	close(fd);
	return (0);
}
