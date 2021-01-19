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

void    ft_pipe(t_shell *shell, t_lines *lst_lines)
{
    int     fd[2];
    
    create_pipe(fd);
    if (shell->output != 0)
        close(fd[1]);
    else 
        shell->output = fd[1];
    prepare_exec(shell, lst_lines);
    launch_exec(shell, lst_lines, shell->input, shell->output);

    shell->input = fd[0]; // we need input fot string with a lift-pipe
}
