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
	char			*symbol;
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


void	split_line(char *line)
{
	int i;
	int j;
	int n;
	char **args;

	n = 0;
	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '|' || line[i] == ';')
			{
				ft_strndup(&line[j], j - i);
				return ;
				// ft_printf("%s, ", args[n]);
				// args[n + 1] = ft_strdup(&line[i]);
				j = i + 1;
			}
		i++;
	}

}

void	parse_functions(t_shell *shell, char *line)
{
	t_fun 	*fun;
	int i;
	i = 0;
	fun = NULL;

	split_line(line, args);

	//fun = add_fun(fun, line);

	// while (fun->next)
	// {
	// 	ft_printf("%s\ns", fun->line);
	// 	fun = fun->next;
	// }
	// ft_printf("%s", fun->line);

	//launch_bin(shell, args, 0, 0);
}
