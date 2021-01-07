
#include "../../headers/minishell.h"
char	*delete_spaces(char *line);
char    *replace_line(t_shell *shell, char *line);


int		empty_line(char *str)
{
	int i;
	i = 0;

	while(str[i] != '\0')
	{
		if (str[i] != ' ')
			return 0;
		i++;
	}
	return (-1);
}

int		error_check(t_lines *lst_lines)
{
    char symbol;

    while (lst_lines)
	{
        if (!(lst_lines->symbol))
          return 0;
      	symbol = *lst_lines->symbol;
      	if ((empty_line(lst_lines->line)) && (symbol == ';' || symbol == '|'))
      	{
      		ft_printf("syntax error near unexpected token `");
      		ft_printf("%c", symbol);
      		ft_printf("\'\n");
      		return -1;
      	}
		lst_lines = lst_lines->next;		
	}
	return 0;
}

// void	lines_preprocessing(t_shell *shell, t_lines *lst_lines)
// {
// 	(void)shell;
// 	while(lst_lines)
// 	{
// 		lst_lines->line = delete_spaces(lst_lines->line);
// 		// lst_lines->line = replace_line(shell, lst_lines->line);
// 		// lst_lines->argv = ft_split(lst_lines->line, ' ');
// 		if (!(lst_lines->next))
// 			break ;
// 		lst_lines = lst_lines->next;
// 	}
// }
