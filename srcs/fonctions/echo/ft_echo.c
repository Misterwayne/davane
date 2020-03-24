#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include  <string.h>

int	ft_len(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}


void	print_arguments(char **argv)
{
	int i;

	i = 1;

	while (argv[i] != NULL)
	{
		printf("%s", argv[i]);
		i++;
	}
}

void	add_text(char **argv, int fd)
{
	char *buf;
	int ret;

	ret = 1;
	printf("add_text");
	while (ret != 0)
		ret = read(fd, buf, 1);
	write(fd, argv[1], ft_len(argv[1]));
	write(fd, "\n", 1);
}

void	rewrite_text(char **argv, int fd)
{
	char *buf;

	printf("rewrite_text");
	write(fd, argv[1], ft_len(argv[1]));
	write(fd, "\n", 1);
}

void open_write(char **argv)
{
	int fd;
	char *buf;

	fd = open("text.txt", O_RDWR);

	if (strcmp(argv[2], ">>") == 0)
		add_text(argv, fd);
	else if (strcmp(argv[2], ">") == 0)
		rewrite_text(argv, fd);
	else 
		print_arguments(argv);
	close(fd);
}

int main(int argc, char **argv)
{

	for (int i = 0; i < argc; i++) 
		printf("%s, ", argv[i]);
	printf("\n");
	open_write(argv);
	printf("\n");
	return (0);
}