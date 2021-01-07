
#include "../../headers/minishell.h"

char        *replace_line(t_shell *shell, char *line);

int         launch_exec(t_shell *shell, char **args, int input, int output)
{  
    pid_t   pid;
    int     status;
    int     index;
    char    *executable;

	if (!(args) || args[0] == NULL)
		return 0;
    executable = add_path(shell, args);
    index = check_commande(shell->cmd, args[0]);
    if (index == 6)
        {
            shell->last_return = shell->cmd->builtin_array[index](args, shell);
            return (0);
        }
	pid = fork();
    if (pid < 0)
        ft_exit_error(0, "fork error");
    if (pid == 0)
    {
        if (input != 0)
           dup2(input, 0);
        if (output != 0)
           dup2(output, 1);
        if (index >= 0 && index <= 5)
            shell->last_return = shell->cmd->builtin_array[index](args, shell);
        else if ((shell->last_return = execv(executable, args)) == -1) // check for (executable != NULL)
            ft_printf("minishell: command not found: %s\n", args[0]);
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

int     launch_body(t_shell *shell, t_lines *lst_lines)
{
    int     output;
    int     input;
    
    input = 0;
    output = 0;
    while (lst_lines)
	{
        //lst_lines->line = replace_line(shell, lst_lines->line);
        lst_lines->argv = ft_split(lst_lines->line, ' ');
        if (!(lst_lines->symbol))
            return (launch_exec(shell, lst_lines->argv, input, output));
        if (ft_strcmp(lst_lines->symbol, ";") == 0)
            semicolon(shell, lst_lines, input, output);
        else if (ft_strcmp(lst_lines->symbol, "|") == 0)
            input = ft_pipe(shell, lst_lines, input);
        else if (ft_strcmp(lst_lines->symbol, ">") == 0 || ft_strcmp(lst_lines->symbol, ">>") == 0)
            output = ft_redirection(shell, lst_lines);
        else if (ft_strcmp(lst_lines->symbol, "<") == 0)
            input = ft_back_redirection(shell, lst_lines);
        lst_lines = lst_lines->next;
	}
    return (0);
}
