#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../headers/minishell.h"

int					get_next_line(int fd, char **line);
int					has_return(char *str);
char				*join_str(const char *s1, const char *s2);

void	copy_file_data(int fd, int fd_tmp)
{
	int		reader;
	char	*line;

	while ((reader = get_next_line(fd_tmp, &line)) == 1)
	{
		ft_printf("OUT:%s\n", line);
		//write(fd, line, ft_strlen(line));
		free(line);
	}

}

void	add_data(int fd, int fd_tmp)
{
	int		reader;
	char	*line;
	int i;
	i = 0;

	reader = 1;
	//reader = get_next_line(fd_tmp, &line);
	while ((reader = get_next_line(fd_tmp, &line)) == 1)
	{
		ft_printf("OUT:%s\n", line);
		//write(fd, line, ft_strlen(line));
		free(line);
	}
	close(fd);
}

void 	ls_call(int fd)
{
	int status;
	char *data;

	//char *args[] = {"/bin/cat", "new.c", "new.txt", 0};
	char *args[] = {"/bin/pwd", 0};
	if (fork() == 0)
        {
			dup2(fd, 1);	
			execv(args[0], args); // child: call execv with the path and the args
		}
    else
        wait(&status);        // parent: wait for the child (not really necessary)
	ft_printf("success_ls\n");
}

void	open_create_close_file(char *file)
{
	int fd;

	//fd = open(file, O_RDWR | O_CREAT + O_RDWR); // begining of file
	fd = open(file, O_RDWR + O_APPEND | O_CREAT + O_RDWR); // enf of file
	ls_call(fd);
	close (fd);
	printf("succes2\n");
}

void	redirection(char **argv)
{
	int fd3;
	int fd0;
	int reader;
	char *data;

	open_create_close_file("check.c");
	printf("succes1\n");
}

int main(int argc, char **argv)
{
	if (argc != 1)
		redirection(argv);
	else
	{
		printf("enter argumets");
	}
}
