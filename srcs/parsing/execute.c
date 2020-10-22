
#include "../../headers/minishell.h"

char        *replace_line(t_shell *shell, char *line);

int   launch_exec(t_shell *shell, char **args, int input, int output)
{  
    pid_t   pid;
    int     status;
    int     index;
    char    *executable;

	if (!(args) || args[0] == NULL)
		return 0;
    executable = add_path(shell, args);
    index = check_commande(shell->cmd, args[0]);
	pid = fork();
    if (pid < 0)
    {
        ft_printf("fork error");
        exit(1);
    }
    if (pid == 0)
    {
        if (input != 0)
           dup2(input, 0);
        if (output != 0)
           dup2(output, 1);
        if (index < 7 && index > 0)
            shell->last_return = shell->cmd->builtin_array[index](args, shell);
        else if (executable != NULL)
            shell->last_return = execv(executable, args);
        else
        {
            ft_printf("minishell: command not found: %s\n",args[0]);
            return (-1);
        }
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
    int     index;
    
    input = 0;
    output = 0;
    while (lst_lines)
	{
        lst_lines->line = replace_line(shell, lst_lines->line);
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
