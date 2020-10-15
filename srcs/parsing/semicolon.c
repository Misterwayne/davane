#include "../../headers/minishell.h"

void	semicolon(t_shell *shell, t_fun *fun, int input, int output)
{
	if (fun->line[0] == '\0')
	{
		write(2, "syntax error near unexpected token `;\'\n", ft_strlen("syntax error near unexpected token `;\'\n"));
		exit(-1);
	}
    launch_exec(shell, fun->argv, input, output);
}
