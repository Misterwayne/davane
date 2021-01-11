#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/errno.h>
int main()
{
    char *buff;

    buff = malloc(sizeof(char)* 1024);
    getwd(buff);
    write(1, buff, strlen(buff));
    write(1, "!\n", 2);
    free(buff);
    return (0);
}
