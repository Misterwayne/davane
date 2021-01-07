#include "../../headers/minishell.h"

void	semicolon(t_shell *shell, t_lines *lst_lines, int input, int output)
{
    launch_exec(shell, lst_lines->argv, input, output);
}
