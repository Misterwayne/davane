#include "../../headers/minishell.h"
char        *replace_line(t_shell *shell, char *line);

void	semicolon(t_shell *shell, t_lines *lst_lines)
{
        if (!(lst_lines->argv))
        	lst_lines->argv = ft_split(lst_lines->line, ' ');
        lst_lines->cmd = lst_lines->argv[0];
        lst_lines->executable = add_path(shell, lst_lines->cmd);
    	lst_lines->index = check_commande(shell->cmd, lst_lines->cmd);
 
        launch_exec(shell, lst_lines, shell->input, shell->output); //  check previously for an empry line?
}
