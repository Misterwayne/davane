#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include<string.h>


int main(int argc, char **argv)
{
   	int fd[2];
    char	*buf;
    struct stat info;

	int status;
	char *args[] = { "/bin/ca", "file1", 0};
	if (fork() == 0)
    {
    	//dup2(fd[1], 1);
		printf("%d", execv(args[0], args)); // child: call execv with the path and the args
        exit(0);
	}
    else
        wait(&status);        // parent: wait for the child (not really necessary)
    printf("check");
    // strerror;
    //close(fd[1]);
    //close(fd[1]);
    // write(fd[1], "privet", 6);
    
    // buf = malloc(10);
    // read(fd[0], buf, 10);
    // printf("%s", buf);
    // close(fd[0]);
    // close(fd[1]);
	// char *args1[] = { "/bin/cat", 0};
    // if (fork() == 0)
    // {
    //     dup2(fd[0], 0);
    //     execv(args1[0], args1);
    // }
// 	fstat(fd[0], &info);
// 	buf = malloc(info.st_size);
//     read(fd[0], buf, info.st_size);
//     //dup2(fd[0], 0);
    
//    // char *args[] = {"/bin/ls", 0};
//     char *arg[3];
//     arg[0] = "/bin/echo";
//     arg[1] = buf;
//     arg[2] = 0;
//     if (fork() == 0)
//     {
//     	execv(arg[0], arg);
//     }
//     //printf("%s", buf);
//     //write (1, "privet", 6);
//     close(fd[0]);
//     close(fd[1]);

    return (0);
}
