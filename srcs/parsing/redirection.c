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

void 	ls_call(int fd, int action)
{
	int status;
	char *data;
	int fd_tmp;
	
	char	*line;
	int		reader;

	//char *args[] = {"/bin/cat", "new.c", "new.txt", 0};
	char *args[] = {"/bin/ls", 0};
	fd_tmp = open("check", O_RDWR + O_APPEND);
	// if (fork() == 0)
    //     {
	// 		if (action == 0)
	// 			dup2(fd, 1);
	// 		else
	// 		{
	// 			//dup2(fd, 1);
	// 			//fd_tmp = dup2(fd_tmp, 1);
	// 			//add_data(fd, fd_tmp);
	// 		}	
	// 		execv(args[0], args); // child: call execv with the path and the args
	// 	}
    // else
    //     wait(&status);        // parent: wait for the child (not really necessary)
	reader = 1;
	while ((reader = get_next_line(fd, &line)) == 1)
	{
		write(fd_tmp, line, ft_strlen(line));
		//printf("%s", line);
		write(fd_tmp, "\n", 1);
		//free(line);
	}
	//write(fd_tmp, "kiki", 5);
	close (fd_tmp);
	ft_printf("success_ls\n");
}

void	open_create_close_file(char *file)
{
	int fd;

	fd = open(file, O_RDWR | O_CREAT);
	// ls_call(fd, 0); // ">"
	ls_call(fd, 1); // ">>"
	close (fd);
	printf("succes2\n");
}


void	redirection(char **argv)
{
	int fd3;
	int fd0;
	int reader;
	char *data;

	open_create_close_file("new.c");
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
