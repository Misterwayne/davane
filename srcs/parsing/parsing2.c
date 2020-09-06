#include "../../headers/minishell.h"

char	*ft_strndup(char *str, int n)
{
	char	*str_new;
	int		i;

	i = ft_strlen(str);
	if (i > n)
		i = n; 
	if (!(str_new = malloc((sizeof(char) * (i + 1)))))
		return (NULL);
	i = 0;
	while (str[i] && i <= n)
		{
			str_new[i] = str[i];
			i++;
		}
	str_new[i] = '\0';
	return (str);
}


typedef struct functions
{
	char			*line;
	char			*r_symbol;
	char			*l_symbol;
	struct functions *next;
}				t_fun;



t_fun	*create_fun(char *data)
{
	t_fun	*new;
	new = malloc(sizeof(t_fun));
	new->line = data;
	new->next = 0;
	return (new);
}

t_fun	*add_fun(t_fun *fun, char *data)
{
	t_fun *tmp;

	tmp = fun;
	if(!(fun)) 
		return (create_fun(data));
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_fun(data);
	return (fun);	
}


char		*split_line(char *line, char *str, int *i)
{
	char *tmp;
	int j;

	j = 0;	
	while (line[*i] != '\0')
	{
		if (line[*i] == '|')
			return (ft_strdup("|"));
		if (line[*i] == ';')
			return (ft_strdup(";"));
		if (line[*i] == '<')
			return (ft_strdup("<"));
		if (line[*i] == '>' && line[*i + 1] == '>')
			return (ft_strdup(">>"));
		if (line[*i] == '>')
			return (ft_strdup(">"));
		//tmp[j] = line[*i];
		j++;
		(*i)++;
	}
	return (0);
}

void	parse_functions(t_shell *shell, char *line)
{
	t_fun 	*fun;
	char *sep;
	char *str;
	int i;
	int j;

	j = 0;
	i = 0;
	fun = NULL;
	while (line[i] != '\0')
	{
		sep = split_line(line, str, &i);
		if (sep == 0)
			return ;
		ft_printf("sep: %s, ", sep);
		free(sep);
		i++;
	}

	//fun = add_fun(fun, line);

	// while (fun->next)
	// {
	// 	ft_printf("%s\ns", fun->line);
	// 	fun = fun->next;
	// }
	// ft_printf("%s", fun->line);
}
