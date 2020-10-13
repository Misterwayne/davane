#include "../../headers/minishell.h"


int		is_special_symbol(char *str)
{
	if (ft_strcmp(str, ";") == 0 || ft_strcmp(str, ">") == 0 ||
	ft_strcmp(str, ">>") == 0 || ft_strcmp(str, "<") == 0 || ft_strcmp(str, "|") == 0)
		return (1);
	return (0);
}


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
	while (str[i] && i < n)
	{
		str_new[i] = str[i];
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}

t_fun	*create_fun(char *data)
{
	t_fun	*new;
	new = malloc(sizeof(t_fun));
	new->line = data; 
	new->argv = 0;
	new->next = 0;
	new->prev = 0;
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
	tmp->next->prev = tmp;
	return (fun);
}

char		*copy_symbol(char *line, int *i)
{
	char	*str;

	if (line[*i] == '>' && line[*i + 1] == '>')
	{
		str = ft_strndup(&line[*i], 2);
		(*i)++;
	}
	else
		str = ft_strndup(&line[*i], 1);
	(*i)++;
	return(str);
}

char		*copy_line(char *line, int *i)
{
	char	*str;
	int 	j;

	str = 0;
	j = 0;
	while (line[*i + j] != '\0')
	{
		if((line[*i + j] == '|') || (line[*i + j] == '>') || (line[*i + j] == '<') || (line[*i + j] == ';'))
			break ;
		j++;
	}
	str = ft_strndup(&line[*i], j);
	(*i) = (*i) + j;
	return (str);
}

char		*define_split_type(char *line, int *i)
{
	if ((line[*i] == '|') || (line[*i] == '>') || (line[*i] == '<') || (line[*i] == ';'))
		return (copy_symbol(line, i));
	else
		return (copy_line(line, i));
}



void	split_on_arguments(t_fun *fun, t_shell *shell)
{
	int 	i;
	char	**argv;

	while(fun)
	{
		if (!(is_special_symbol(fun->line)))
		{
			i = 0;
			argv = ft_split(fun->line,' ');
			check_v(shell, argv);
			fun->argv = argv;
		}
		if (!(fun->next))
			return ;
		fun = fun->next;
	}
}


void	parse_functions(t_shell *shell, char *line)
{
	t_fun 	*fun;
	char	*str;
	int		i;

	i = 0;
	fun = NULL;
	shell->line = line;
	while (line[i] != '\0')
	{
		str = define_split_type(line, &i);
		fun = add_fun(fun, str);
	}
	split_on_arguments(fun, shell);
	launch_body(shell, fun);
}
