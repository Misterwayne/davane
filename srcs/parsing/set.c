#include "../../headers/minishell.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


char	*call_set(void)
{
    int fd[2];
    char	*buf;
    struct stat info;

	int status;
	char *args[] = { "/bin/zsh", "-c", "set", 0};
    if(pipe(fd) < 0)
    {
        /* Если создать pipe не удалось, печатаем об этом сообщение 
        и прекращаем работу */
        printf("Can\'t create pipe\n");
        exit(-1); 
    }

	if (fork() == 0)
    {
    	dup2(fd[1], 1);
		execv(args[0], args); // child: call execv with the path and the args
	}
    else
        wait(&status);        // parent: wait for the child (not really necessary)
	fstat(fd[0], &info);
	buf = malloc(info.st_size);
    read(fd[0], buf, info.st_size);
    close(fd[0]);
    close(fd[1]);
    return (buf);
}