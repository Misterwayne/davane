#include "../../headers/minishell.h"
char	*ft_strndup(char *str, int n);
void	print_data(t_fun *fun);
void	split_on_arguments(t_fun *fun);
t_fun	*add_fun(t_fun *fun, char *data, char *r_symbol);
void	delete_spaces(char *line);
int	is_even_quotes(char *line);


int		is_special_symbol(char *str)
{
	if (*str == ';' || *str == '>' || *str == '<' || *str == '|')
		return (1);
	return 0;
}

int		skip_quotes(char *str)
{
	int i;
	
	i = 1;
	while (str[i] != '\0')
		{
			if (str[i] == '"')
				return (i);
			i++;
		}
	ft_printf(">");
	exit(0);
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

t_fun	*separator(char *str, t_fun *fun)
{
	int	i;
	char *symbol;

	i = 0;
	if (*str == '\0')
		return (fun);
	while (str[i])
	{
		if (str[i] == '"')
			i = i + skip_quotes(str + i);
		if (is_special_symbol(str + i))
			{
				//ft_printf("special line: %s\n", ft_strndup(str, i));
				symbol = copy_symbol(str + i);
				fun = add_fun(fun, ft_strndup(str, i), symbol);
				fun = separator(str + i + ft_strlen(symbol), fun);
				return (fun);
			}
		i++;
	}
	//ft_printf(" simple line: %s\n", str);
	fun = add_fun(fun, ft_strdup(str), 0);
	return (fun);
}

void	parse_functions(t_shell *shell, char *line)
{
	t_fun 	*fun;
	int		i;

	if (is_even_quotes(line) != 0)
		{
			ft_printf(">\n");
			exit(0);
		}
	delete_spaces(line);
	ft_printf("%s", line);
	fun = NULL;
	fun = separator(line, fun);
	split_on_arguments(fun);
	// print_data(fun);
	// launch_body(shell, fun);
}
