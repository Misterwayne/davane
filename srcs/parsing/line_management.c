
#include "../../headers/minishell.h"
char    *replace_line(t_env *env, char *line);
char	*delete_spaces(char *line);

void	lines_preprocessing(t_shell *shell, t_lines *lst_lines)
{
	while(lst_lines)
	{
		lst_lines->line = delete_spaces(lst_lines->line);
		lst_lines->line = replace_line(shell->env, lst_lines->line);
		lst_lines->argv = ft_split(lst_lines->line, ' ');
		check_v(shell, lst_lines->argv);
		if (!(lst_lines->next))
			break ;
		lst_lines = lst_lines->next;
	}
}
