#include "../../headers/minishell.h"
char        *replace_line(t_shell *shell, char *line);

void	semicolon(t_shell *shell, t_lines *lst_lines, int input, int output)
{
        if (!(lst_lines->argv))
        	lst_lines->argv = ft_split(lst_lines->line, ' ');
        lst_lines->cmd = lst_lines->argv[0];
        lst_lines->executable = add_path(shell, lst_lines->cmd);
    	lst_lines->index = check_commande(shell->cmd, lst_lines->cmd);
        //ft_printf("%s, %s, %d, %s\n ",  lst_lines->argv[0], lst_lines->cmd, lst_lines->index, lst_lines->executable);
        // ft_printf("OK");
        //ft_printf("%d", input);
        launch_exec(shell, lst_lines, input, output); //  check previously for an empry line?
}
