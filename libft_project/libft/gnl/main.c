#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int		get_next_line(int fd, char **line);
int main ()
{
	char	**line;
	int		fd;

	line = malloc(1);
	fd = open("text.txt", O_RDONLY);
	while (get_next_line(fd, line))
		printf("%s\n", *line);
	close(fd);
	return (0);
}
