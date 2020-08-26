#include "../../headers/minishell.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "../../headers/minishell.h"

int					get_next_line(int fd, char **line);
char				*join_str(const char *s1, const char *s2);
void				print_arguments(char **argv, t_env *env);

// void 	call_binaries(int fd)
// {
// 	int status;
// 	char *data;

// 	//char *args[] = {"/bin/cat", "new.c", "new.txt", 0};
// 	char *args[] = {"/bin/pwd", 0};
// 	if (fork() == 0)
//         {
// 			dup2(fd, 1);	
// 			execv(args[0], args); // child: call execv with the path and the args
// 			exit(0); // not sure if it works this way
// 		}
//     else
//         wait(&status);        // parent: wait for the child (not really necessary)
// 	ft_printf("success_ls\n");
// }

// void	call_builtin(char **argv, int fd)
// {
// 	int status;
// 	char *data;

// 	if (fork() == 0)
//     {
// 		dup2(fd, 1);	
// 		print_arguments(argv, 0); // child: call execv with the path and the args
// 		exit(0);
// 	}
//     else
//         wait(&status);        // parent: wait for the child (not really necessary)
// 	ft_printf("success1\n");
// }

char	*check_for_file(char **argv, int i)
{
	char *file;

	if (argv[i + 1])
		file = argv[i + 1];
	else
		{
			ft_printf("parse error near \'\\n\n");
			exit (-1); 
		}
	return (file);
}

void	redirect_output(char **argv, int fd)
{
	int status;
	char *data;
	char *args[] = {"/bin/pwd", 0};

	//call_builtin(argv, fd); // for builtins
	//call_binaries(fd); // for binaries
	if (fork() == 0)
    {
		dup2(fd, 1);	
		if (ft_strcmp(argv[0], "pwd") == 0)
			execv(args[0], args); // child: call execv with the path and the args
		else if (ft_strcmp(argv[0], "echo") == 0)
			print_arguments(argv, 0); // child: call execv with the path and the args
		exit(0);
	}
    else
        wait(&status);        // parent: wait for the child (not really necessary)
	ft_printf("success2\n");
}

void	redirect_input(char **argv, char *file)
{
	int status;
	char *data;
	char *args[] = {"/bin/cat", file, 0};

	if (fork() == 0)
    {
		execv(args[0], args); // child: call execv with the path and the args
		exit(0);
	}
    else
        wait(&status);        // parent: wait for the child (not really necessary)
}

void	write_to_file(char **argv, char **argv_new, int i)
{
	char	*file;
	int		fd;

	file = check_for_file(argv, i);
	fd = open(file, O_APPEND | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
	redirect_output(argv_new, fd);
	close (fd);
}

void	rewrite_the_file(char **argv, char **argv_new, int i)
{
	char	*file;
	int		fd;

	file = check_for_file(argv, i);
	fd = open(file, O_TRUNC | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	redirect_output(argv_new, fd);
	close (fd);
}

void	read_from_file(char **argv, char **argv_new, int i)
{
	char	*file;
	int		fd;

	file = check_for_file(argv, i);
	redirect_input(argv_new, file);
}


void	split_redirection(char **argv, int i)
{
	char 	**argv_new;
	int 	j;

	j = 0;
	argv_new = malloc(sizeof(char *)*i);
	while(j + 1 < i)
	{
		argv_new[j] = ft_strdup(argv[j + 1]);
		//printf("%s\n", argv_new[j]);
		j++;
	}
	argv_new[j] = NULL;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(">", argv[i]) == 0)
			rewrite_the_file(argv, argv_new, i);
		if (ft_strcmp(">>", argv[i]) == 0)
			write_to_file(argv, argv_new, i);
		if (ft_strcmp("<", argv[i]) == 0)
			read_from_file(argv, argv_new, i);
		i++;
	}
	exit(0);
}

int find_redirection(char **argv)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		if ((ft_strcmp(">", argv[i]) == 0) || (ft_strcmp(">>", argv[i]) == 0) ||
			(ft_strcmp(">", argv[i]) == 0) || (ft_strcmp("<", argv[i]) == 0))
			split_redirection(argv, i);
		i++;
	}
	return (0);
}
