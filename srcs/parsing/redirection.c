#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../headers/minishell.h"

int					get_next_line(int fd, char **line);
int					has_return(char *str);
char				*join_str(const char *s1, const char *s2);
void	print_arguments(char **argv, t_env *env);

void 	call_binaries(int fd)
{
	int status;
	char *data;

	//char *args[] = {"/bin/cat", "new.c", "new.txt", 0};
	char *args[] = {"/bin/ls", 0};
	if (fork() == 0)
        {
			dup2(fd, 1);	
			execv(args[0], args); // child: call execv with the path and the args
			exit(0); // not sure if it works this way
		}
    else
        wait(&status);        // parent: wait for the child (not really necessary)
	ft_printf("success_ls\n");
}

void	call_builtin(char **argv, int fd)
{
	int status;
	char *data;

	if (fork() == 0)
    {
		dup2(fd, 1);	
		print_arguments(argv, 0);// child: call execv with the path and the args
		exit(0);
	}
    else
        wait(&status);        // parent: wait for the child (not really necessary)
	printf("succ");
}

void	redirection(char **argv, char *file)
{
	int fd;

	//fd = open(file, O_TRUNC | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR |  S_IRGRP | S_IROTH); // begining of file
	fd = open(file, O_APPEND | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR |  S_IRGRP | S_IROTH); // enf of file
	call_binaries(fd); // for binaries
	//call_builtin(argv, fd); // for builtins
	close (fd);
	printf("succes2\n");
}

int main(int argc, char **argv)
{
	if (argc != 1)
		redirection(argv, "check.c");
	else
	{
		printf("enter argumets");
	}
}
