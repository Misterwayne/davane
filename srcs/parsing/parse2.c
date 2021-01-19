#include "../../headers/minishell.h"

static int   open_file(char *symbol, char *file)
{
    int     fd;

    if (!(file))
        {
            ft_printf("sh:  syntax error near unexpected token `newline\'\n");
            exit(-1);
        }
    if (ft_strcmp(symbol, ">>") == 0)
        fd = open(file, O_APPEND | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
    else
        fd = open(file, O_TRUNC | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    return (fd);
}

int			find_redirection(char *line)
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
		else if ((line[i] == '>' ||  line[i] == '<') && flag == 0) // find |>;<
			return (i);
		i++;
	}
	return (-1);
}

static void		add_to_end(t_files **begin_list, t_files *elem)
{
	t_files *tmp;
	
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

static t_files 	*create_elem(char *name, char *symbol)
{
	t_files *elem;

	elem = malloc(sizeof(t_files));
	elem->name = name;
	elem->symbol = symbol;
	elem->next = NULL;
	return (elem);
}

static		t_files *file_name(char *line)
{
	char 		*name;
	char 		*symbol;
	t_files 	*elem;
	int i;
	int len;

	i = 1;
	len = 0;
	if (line[0] == line[1])
		i = 2;
	symbol = ft_strndup(line, i);
	while (line[i] == ' ')
		i++;
	while (line[i + len] != '\0' && line[i + len] != ' ' && line[i + len] != '>' &&  line[i + len] != '<')
		len++;
	name = ft_strndup(line + i, len);
	return (create_elem(name, symbol));
}

void	redirect(t_lines *lst_lines, int i)
{
	t_files 	*elem;
	char 		*str1;
	char 		*str2;

	i = find_redirection(lst_lines->line);
	elem = file_name(lst_lines->line + i);
	add_to_end(&lst_lines->files, elem);
	str1 = ft_strndup(lst_lines->line, i);
	str2 = ft_strstr(lst_lines->line + i, elem->name) + ft_strlen(elem->name);
	free(lst_lines->line);
	lst_lines->line = ft_strjoin(str1, str2);
	free(str1);
}

void parse_redirections(t_lines *lst_lines)
{
	char	*name;
	int		i;

	while (lst_lines)
	{
		while ((i = find_redirection(lst_lines->line)) != -1)
			redirect(lst_lines, i);
		lst_lines = lst_lines->next;
	}
}
