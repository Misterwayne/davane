#include "../../headers/minishell.h"
char        *replace_line(t_shell *shell, char *line);

void	semicolon(t_shell *shell, t_lines *lst_lines)
{
	prepare_exec(shell, lst_lines);
    launch_exec(shell, lst_lines, shell->input, shell->output); //  check previously for an empry line?
}
