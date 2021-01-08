
#include "../../headers/minishell.h"
char      *delete_spaces(char *line);
char      *replace_line(t_shell *shell, char *line);

int     check_commande(t_cmd *cmd, char *line)
{
    int i;

    i = 0;
    if (line == NULL)
        return (-3);
    while (cmd->cmd_lst[i] != NULL)
    {
        if (ft_strcmp(cmd->cmd_lst[i], line) == 0)
            return (i);
        i++;
    }
    return (-2);
}

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
    char *symbol;

    while (lst_lines)
	{
        if (!(lst_lines->symbol))
          return 0;
      	symbol = lst_lines->symbol;
      	if ((empty_line(lst_lines->line)) && (*symbol == ';' || *symbol == '|'))
      	{
      		ft_printf("minishell: syntax error near unexpected token `");
      		ft_printf("%c", symbol);
      		ft_printf("\'\n");
      		return -1;
      	}
        if (*symbol == '>') 
          if (empty_line(lst_lines->next->line))
            {
              ft_printf("minishell: syntax error near unexpected token `newline\'\n");
              return -1;
            }
		lst_lines = lst_lines->next;		
	}
	return 0;
}