#include "../../headers/minishell.h"

t_lines		*add_lst_lines(t_lines *fun, char *data, char *r_symbol);
char		*ft_strndup(char *str, int n);
char		*quotes(char *line);

int			is_special_symbol(char *str)
{
	if (*str == ';' || *str == '>' || *str == '<' || *str == '|')
		return (1);
	return 0;
}

char		*copy_symbol(char *str)
{
	char	*symbol;

	if (*str == '>' && *(str + 1) == '>')
		{
			symbol = ft_strndup(&*str, 2);
			return(symbol);
		}
	symbol = ft_strndup(str, 1);
	return(symbol);
}

int			skip_quotes(char *str, char quotes)
{
	int i;
	
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == quotes && (i == 1 || str[i - 1] != '\\'))
			return (i);
		i++;
	}
	return (i);
}

t_lines		*cut_line(char *str, t_lines *lst_lines)
{
	int	i;
	char *symbol;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '"' || str[i] == '\'') && (i == 0 || str[i - 1] != '\\'))
			i = i + skip_quotes(str + i, str[i]);
		else if (is_special_symbol(str + i))
		{
			symbol = copy_symbol(str + i);
			lst_lines = add_lst_lines(lst_lines, ft_strndup(str, i), symbol);
			lst_lines = cut_line(str + i + ft_strlen(symbol), lst_lines);
			return (lst_lines);
		}
		i++;
	}
	lst_lines = add_lst_lines(lst_lines, ft_strdup(str), 0);
	return (lst_lines);
}
