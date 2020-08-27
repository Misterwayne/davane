#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
   	int fd[2];
    char	*buf;
    struct stat info;

	int status;
	char *args[] = { "/bin/ls", 0};
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
    //dup2(fd[0], 0);
    
   // char *args[] = {"/bin/ls", 0};
    char *arg[3];
    arg[0] = "/bin/echo";
    arg[1] = buf;
    arg[2] = 0;
    if (fork() == 0)
    {
    	execv(arg[0], arg);
    }
    //printf("%s", buf);
    //write (1, "privet", 6);
    close(fd[0]);
    close(fd[1]);

    return (0);
}