#include "../../headers/minishell.h"
char	*ft_strndup(char *str, int n);
void	print_data(t_lines *fun);
void	lines_preprocessing(t_shell *shell, t_lines *fun);
t_lines	*add_lst_lines(t_lines *fun, char *data, char *r_symbol);
char	*quotes(char *line);

int			is_special_symbol(char *str)
{
	if (*str == ';' || *str == '>' || *str == '<' || *str == '|')
		return (1);
	return 0;
}

int			skip_quotes(char *str, char quotes)
{
	int i;
	
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == quotes)
			return (i);
		i++;
	}
	return (i);
}

char		*copy_symbol(char *str)
{
	char	*symbol;

	if (*str == '>' && *(str + 1) == '>')
		{
			symbol = ft_strndup(&*str, 2);
			return(symbol);
		}
	symbol = ft_strndup(&*str, 1);
	return(symbol);
}

t_lines		*separator(char *str, t_lines *lst_lines)
{
	int	i;
	char *symbol;

	i = 0;
	if (*str == '\0')
		return (lst_lines);
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			i = i + skip_quotes(str + i, str[i]);
		if (is_special_symbol(str + i))
			{
				symbol = copy_symbol(str + i);
				lst_lines = add_lst_lines(lst_lines, ft_strndup(str, i), symbol);
				lst_lines = separator(str + i + ft_strlen(symbol), lst_lines);
				return (lst_lines);
			}
		i++;
	}
	lst_lines = add_lst_lines(lst_lines, ft_strdup(str), 0);
	return (lst_lines);
}

void		parse_functions(t_shell *shell, char *line)
{
	t_lines 	*lst_lines;

	lst_lines = NULL;
	line = quotes(line);
	lst_lines = separator(line, lst_lines);
	lines_preprocessing(shell, lst_lines);
	//print_data(lst_lines);
	launch_body(shell, lst_lines);
}
