
#include "../../headers/minishell.h"

char        *replace_line(t_shell *shell, char *line);

void        close_used_fd(t_shell *shell)
{
    if (shell->input != 0)
    {
        close (shell->input);
        shell->input = 0;
    }
    if (shell->output != 0)
    {
        close (shell->output);
        shell->output = 0;
    }
}

int         launch_exec(t_shell *shell, t_lines *lst_lines, int input, int output)
{  
    pid_t   pid;
    int     status;

    if (lst_lines->index >= 0 && lst_lines->index <= 5)
    //if (lst_lines->index == 2 || lst_lines->index == 4 || lst_lines->index == 6)
        {
            // export(lst_lines->argv, shell);
            shell->cmd->builtin_array[lst_lines->index](lst_lines->argv, shell);
            close_used_fd(shell); // should check
            return 0;
        }
    if ((pid = fork()) < 0)
        ft_exit_error(0, "fork error");
    if (pid == 0)
    {
        //ft_printf("OK");
        if (shell->input != 0)
           dup2(shell->input, 0);
        if (shell->output != 0)
           dup2(shell->output, 1);
        // if (lst_lines->index >= 0 && lst_lines->index <= 5 && lst_lines->index != 1)
        //     shell->last_return = shell->cmd->builtin_array[lst_lines->index](lst_lines->argv, shell);
        // else
        shell->last_return = execv(lst_lines->executable, lst_lines->argv); // add if shell->last_return == -1 ft_printf("minishell: %s: command not found\n", args[0]);
        //shell->last_return = shell->cmd->builtin_array[lst_lines->index](lst_lines->argv, shell);
        //export(lst_lines->argv, shell);
        exit(0);
    }
    else
    {
        shell->last_pid = pid;
        wait(&status);
    }
    close_used_fd(shell);
    return (0);
}

void     prepare_exec(t_shell *shell, t_lines *lst_lines)
{
    //lst_lines->line = replace_line(shell, lst_lines->line);
    
    if (!(lst_lines->argv))
        //lst_lines->argv = ft_split(lst_lines->line, ' ');
        lst_lines->argv = ft_split_argv(lst_lines->line);
    lst_lines->cmd = lst_lines->argv[0];
    lst_lines->executable = add_path(shell, lst_lines->cmd);
    lst_lines->index = check_commande(shell->cmd, lst_lines->cmd);
    if (lst_lines->index == 6)
        shell->last_return = shell->cmd->builtin_array[6](lst_lines->argv, shell);
    // int i = 0;
    // while (lst_lines->argv[i])
    //     ft_printf("%s", lst_lines->argv[i++]);
    // ft_printf("\n");
    // need to check if it is possible to execute this
}

int     launch_body(t_shell *shell, t_lines *lst_lines)
{   
    shell->input = 0;
    shell->output = 0;
    while (lst_lines)
	{
        //prepare_exec(shell, lst_lines);
        if (!(lst_lines->symbol) || (ft_strcmp(lst_lines->symbol, ";") == 0))
            semicolon(shell, lst_lines);
        else if (ft_strcmp(lst_lines->symbol, "|") == 0)
            ft_pipe(shell, lst_lines);
        else if (ft_strcmp(lst_lines->symbol, ">") == 0 || ft_strcmp(lst_lines->symbol, ">>") == 0)
            ft_redirection(shell, lst_lines);
        else if (ft_strcmp(lst_lines->symbol, "<") == 0)
            ft_back_redirection(shell, lst_lines);
        lst_lines = lst_lines->next;
	}
    return (0);
}
