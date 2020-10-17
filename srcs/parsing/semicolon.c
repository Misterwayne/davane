#include "../../headers/minishell.h"

void	semicolon(t_shell *shell, t_lines *lst_lines, int input, int output)
{
	if (lst_lines->line[0] == '\0')
	{
		write(2, "syntax error near unexpected token `;\'\n", ft_strlen("syntax error near unexpected token `;\'\n"));
		exit(-1);
	}
    launch_exec(shell, lst_lines->argv, input, output);
}
