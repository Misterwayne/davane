
#include "../../headers/minishell.h"

char        *replace_line(t_shell *shell, char *line);
void        simple(t_shell *shell, char **args, int input, int output);

int         launch_exec(t_shell *shell, t_lines *lst_lines, int input, int output)
{  
    pid_t   pid;
    int     status;

    if ((pid = fork()) < 0)
        ft_exit_error(0, "fork error");
    if (pid == 0)
    {
        if (input != 0)
           dup2(input, 0);
        if (output != 0)
           dup2(output, 1);
        // if (lst_lines->index >= 0 && lst_lines->index <= 5)
        //     shell->last_return = shell->cmd->builtin_array[index](lst_lines->argv, shell);
        // else
        shell->last_return = execv(lst_lines->executable, lst_lines->argv); // add if shell->last_return == -1 ft_printf("minishell: %s: command not found\n", args[0]);
        exit(0);
    }
    else
    {
        shell->last_pid = pid;
        wait(&status);
    }
    if (input != 0)
        close (input);
    if (output != 0)
        close (output);
    return (0);
}


void     fill_data(t_shell *shell, t_lines *lst_lines)
{
    //lst_lines->line = replace_line(shell, lst_lines->line);
    lst_lines->argv = ft_split(lst_lines->line, ' ');
    if (!(lst_lines->argv) || lst_lines->argv[0] == NULL)
        return ;
    lst_lines->executable = add_path(shell, lst_lines->cmd);
    lst_lines->index = check_commande(shell->cmd, lst_lines->cmd);
    if (lst_lines->index == 6)
    {
        shell->last_return = shell->cmd->builtin_array[6](lst_lines->argv, shell);
        return ;
    }
}

int     launch_body(t_shell *shell, t_lines *lst_lines)
{
    int     output;
    int     input;
    
    input = 0;
    output = 0;
    while (lst_lines)
	{
        //if (!(lst_lines->argv))
        //    fill_data(shell, lst_lines);
        if (!(lst_lines->symbol) || (ft_strcmp(lst_lines->symbol, ";") == 0))
            semicolon(shell, lst_lines, input, output);
        else if (ft_strcmp(lst_lines->symbol, "|") == 0)
            input = ft_pipe(shell, lst_lines, input, output);
        else if (ft_strcmp(lst_lines->symbol, ">") == 0 || ft_strcmp(lst_lines->symbol, ">>") == 0)
            output = ft_redirection(shell, lst_lines, input);
        // else if (ft_strcmp(lst_lines->symbol, "<") == 0)
        //     input = ft_back_redirection(shell, lst_lines);
        lst_lines = lst_lines->next;
	}
    return (0);
}
