#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../gnl/get_next_line.h"

void	display_var(char **argv)
{
	int fd;
	int red;
	char *line;

	fd = open("var.txt", O_RDONLY);
	red = 1;
	while(red == 1)
	{
		red = get_next_line(fd, &line);
		printf("%s\n", line);
		//free(line);
	}
	close(fd);
}

int main(int argc, char **argv)
{
	 if (argc == 1)
		display_var(argv);
	return (0);
}
