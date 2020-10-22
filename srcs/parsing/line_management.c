
#include "../../headers/minishell.h"
char	*delete_spaces(char *line);
void	semicolon_errors(t_lines *lst_lines);
void	pipe_errors(t_lines *lst_lines);
char    *replace_line(t_shell *shell, char *line);
void    redirection_errors(t_lines *lst_lines);

void	error_check(t_lines *lst_lines)
{
    while (lst_lines)
	{
        if (!(lst_lines->symbol))
          return ;
        if (ft_strcmp(lst_lines->symbol, ";") == 0)
            semicolon_errors(lst_lines);
        else if (ft_strcmp(lst_lines->symbol, "|") == 0)
            pipe_errors(lst_lines);
        else if (ft_strcmp(lst_lines->symbol, ">") == 0 || ft_strcmp(lst_lines->symbol, ">>") == 0)
			redirection_errors(lst_lines);
        else if (ft_strcmp(lst_lines->symbol, "<") == 0)
			redirection_errors(lst_lines);
		lst_lines = lst_lines->next;		
	}
}

void	lines_preprocessing(t_shell *shell, t_lines *lst_lines)
{
	while(lst_lines)
	{
		lst_lines->line = delete_spaces(lst_lines->line);
		// lst_lines->line = replace_line(shell, lst_lines->line);
		// lst_lines->argv = ft_split(lst_lines->line, ' ');
		if (!(lst_lines->next))
			break ;
		lst_lines = lst_lines->next;
	}
}
