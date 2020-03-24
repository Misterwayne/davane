#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	if (pid == 0)
	{
		char *args[] = {"echo", "put text in myfile", ">>", "file_name", NULL};
		execvp("./ft_echo", args);
	}
	
	wait(NULL);
	printf("PARENT PROCESS");
	return (0);
}