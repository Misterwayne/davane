#include "../../headers/minishell.h"

int     create_pipe(int *fd)
{
    if(pipe(fd) < 0)
    {
        ft_printf("Can\'t create pipe\n");
        exit(-1); 
    }
    return (0);
}

int     ft_pipe(t_shell *shell, t_lines *lst_lines, int input, int output)
{
    int     fd[2];
    // int     output;
    char *buf;
    
    create_pipe(fd);
    if (output != 0)
        close(fd[1]);
    else 
        output = fd[1];
    // //ft_printf("%s, %d, %s\n ",  lst_lines->cmd, lst_lines->index, lst_lines->executable); 
    // launch_exec(shell, lst_lines, input, fd[1]);
    launch_exec(shell, lst_lines, input, output);
    input = fd[0];
    //close(fd[0]);


    // write(fd[1], "privet", 6);    // check whats in buffer - delete after working with it
    // buf = malloc(15);
    // read(fd[0], buf, 15);
    // ft_printf("%s", buf);
    // close(fd[1]);

    return (input);
}