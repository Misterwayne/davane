
#include "../../headers/minishell.h"

void	free_struct(t_fun *fun)
{
	if (fun->argv);
		// free_2d_array(fun->argv);
	if (fun->line);
		// free(fun->line);
}

int   launch_exec(t_shell *shell, char **args, int input, int output)//probleme when a built-in is called with a redirection (stdin is stuck on 0)
{  
	pid_t   pid;
	int     status;
	int     i;
	char *executable;

	if (!(args))
		return (0);
	executable = add_path(shell, args);
	i = check_commande(shell->cmd, args[0]);
	if (i == 6)
		shell->cmd->builtin_array[i](args, shell);
	if (i == -1 && executable == 0)
	{
		ft_printf("minishell: %s: command not found\n", args[0]);
		// free(executable);
		// free_2d_array(args);
		// free(args);
		return (0);
	}
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
		if (i >= 0 && i < 6)
			shell->cmd->builtin_array[i](args, shell);
		else
			execv(executable, args);
	}
	else
		wait(&status);
	if (input != 0)
		close (input);
	if (output != 0)
		close (output);
	// free(executable);
	// free_2d_array(args);
	// free(args);
	return (0);
}

int     launch_body(t_shell *shell, t_fun *fun)
{
	int output;
	int input;
	
	input = 0;
	output = 0;
	while (fun)
	{
		if (ft_strcmp(fun->line, ";") == 0)
			semicolon(shell, fun, input, output);
		else if (ft_strcmp(fun->line, "|") == 0)
		{
			input = ft_pipe(shell, fun, input);
		}
		else if (ft_strcmp(fun->line, ">") == 0 || ft_strcmp(fun->line, ">>") == 0)
		{
			output = ft_redirection(shell, fun);
		}
		else if (ft_strcmp(fun->line, "<") == 0)
		{
			input = ft_back_redirection(shell, fun);
		}
		if (!(fun->next))
			return (launch_exec(shell, fun->argv, input, output));
		fun = fun->next;
	}
	free_struct(fun);
	return (0);
}
