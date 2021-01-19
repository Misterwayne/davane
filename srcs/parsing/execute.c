
#include "../../headers/minishell.h"

void        close_used_fd(t_lines *lst_lines)
{
    if (lst_lines->input != 0)
    {
        close (lst_lines->input);
        lst_lines->input = 0;
    }
    if (lst_lines->output != 0)
    {
        close (lst_lines->output);
        lst_lines->output = 0;
    }
}

void        pipe_functions(t_shell *shell, t_lines *lst_lines)
{
    pid_t   pid;
    int     status;

    if ((pid = fork()) < 0)
        ft_exit_error(0, "fork error");
    if (pid == 0)
    {
        //ft_printf("OK");
        if (lst_lines->input != 0)
           dup2(lst_lines->input, 0);
        if (lst_lines->output != 0)
           dup2(lst_lines->output, 1);
        if (lst_lines->index >= 4 && lst_lines->index <= 6)
            shell->last_return = shell->cmd->builtin_array[lst_lines->index](lst_lines->argv, shell);
        else
            shell->last_return = execv(lst_lines->executable, lst_lines->argv); // add if shell->last_return == -1 ft_printf("minishell: %s: command not found\n", args[0])
        exit(-1);
    }
    else
    {
        shell->last_pid = pid;
        wait(&status);
    }
    // ft_printf("%d,", status);
    // ft_printf("%d, ", shell->last_return);
    close_used_fd(lst_lines);
}

int         launch_exec(t_shell *shell, t_lines *lst_lines)
{  
    if (lst_lines->index >= 0 && lst_lines->index <= 3)
        {
            shell->last_return = shell->cmd->builtin_array[lst_lines->index](lst_lines->argv, shell);
            close_used_fd(lst_lines); // should check
            return 0;
        }
    pipe_functions(shell, lst_lines);
    return (0);
}
