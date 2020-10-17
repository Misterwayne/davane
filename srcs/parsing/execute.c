
#include "../../headers/minishell.h"

int   launch_exec(t_shell *shell, char **args, int input, int output)
{  
    pid_t   pid;
    int     status;
    char *executable;

	if (!(args))
		return 0;
    executable = add_path(shell, args);
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
        execv(executable, args);
    }
    else
        wait(&status);
    if (input != 0)
        close (input);
    if (output != 0)
        close (output);
    return (0);
}

int     launch_body(t_shell *shell, t_lines *lst_lines)
{
    int output = 0;
    int input = 0;

    while (lst_lines)
	{
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
