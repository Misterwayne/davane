#include "../../headers/minishell.h"

static void			add_to_end(t_lines **begin_list, t_lines *elem)
{
	t_lines *tmp;
	
	if (!(*begin_list))
		*begin_list = elem; 
	else
	{
		tmp = *begin_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}

static t_lines		*create_elem(char *data)
{
	t_lines	*new;

	new = malloc(sizeof(t_lines));
	new->line = data;
	new->argv = NULL;
	new->executable = NULL;
	new->c = '0';
	new->file = NULL;
	new->file_flag = 0;
	new->index = -1;
	new->input = 0;
	new->output = 0;
	new->next = NULL;
	new->files = NULL;
	return (new);
}

static int	find_symbol(char *line)
{
	int i;
	char flag;
	char *str;

	i = 0;
	flag = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\\' && line[i + 1] != '\0') // skip special symbols
			i += 2;
		else if (line[i] == '\'' || line[i] == '\"') // skip symbols in quotes
			if (flag == 0)
				flag = line[i];
			else
				flag = 0;
		else if ((line[i] == '|' ||  line[i] == ';') && flag == 0) // find |>;<
			return (i);
		i++;
	}
	return (i);
}

int	fill_stucture(t_lines **lst_lines, char *line, int i)
{
	char *str;
	t_lines *elem;

	str = ft_strndup(line, i);
	elem = create_elem(str);
	add_to_end(lst_lines, elem);
	if (line[i] == ';' || line[i] == '|')
		{
			elem->c = line[i];
			if (empty_line(str))
				{
					ft_printf("minishell: syntax error near unexpected token `");
					ft_printf("%c", elem->c);
					ft_printf("\'\n");
					return (-1);
				}
		}
	return (0);
}

int 	parse(char *line, t_lines **lst_lines)
{
	int i;
	
	while (line)
	{
		i = find_symbol(line);
		if (fill_stucture(lst_lines, line, i) == -1)
			return (-1);
		if (line[i] == '\0')
			break;
		// if (line[i] == '|' && empty_line(line + i + 1))
		// {
		// 	free(line);
		// 	ft_printf(">");
		// 	get_next_line(0, &line);
		// 	i = 0;
		// 	continue;
		// }
		line = line + i + 1;
	}
	return (0);
}
