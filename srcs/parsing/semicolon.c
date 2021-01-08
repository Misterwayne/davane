#include "../../headers/minishell.h"


void simple(t_shell *shell, char **args, int input, int output) // probably can be deleted
{
	launch_exec(shell, args, input, output); 
}

void	semicolon(t_shell *shell, t_lines *lst_lines, int input, int output)
{
    lst_lines->argv = ft_split(lst_lines->line, ' ');
    launch_exec(shell, lst_lines->argv, input, output); //  check previously for an empry line?
}
