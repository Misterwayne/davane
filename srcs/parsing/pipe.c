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
    // int     output;
    char *buf;
    

    if (!(lst_lines->argv))
        lst_lines->argv = ft_split(lst_lines->line, ' ');
    lst_lines->cmd = lst_lines->argv[0];
    lst_lines->executable = add_path(shell, lst_lines->cmd);
    lst_lines->index = check_commande(shell->cmd, lst_lines->cmd);

    create_pipe(fd);
    if (shell->output != 0)
        close(fd[1]);
    else 
        shell->output = fd[1];
    launch_exec(shell, lst_lines, shell->input, shell->output);

    shell->input = fd[0]; // we need input fot string with a lift-pipe
}