#include "../../headers/minishell.h"

void		print_data(t_lines *fun);
static t_lines		*create_elem(char *data)
{
	t_lines	*new;

	new = malloc(sizeof(t_lines));
	new->line = data;
	new->argv = NULL;
	new->executable = NULL;
	new->file = NULL;
	new->file_flag = 0;
	new->index = -1;
	new->input = 0;
	new->output = 0;
	new->next = NULL;
	return (new);
}

static void	add_to_end(t_lines **begin_list, t_lines *elem)
{
	t_lines *tmp;
	
	tmp = *begin_list;
	if (!(tmp)) 
		*begin_list = elem; 
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}


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

static int     create_pipe(t_lines *elem)
{
   int     fd[2];
   
   if(pipe(fd) < 0)
    {
        ft_printf("Can\'t create pipe\n");
        exit(-1); 
    }
   elem->output = fd[1];
   return (fd[0]);
}

static char	*split_name(char *line)
{
	char *name;
	char *line_cleaned;
	int i;
	
	line_cleaned = ft_strtrim(line, " >");
	i = 0;
	while (line_cleaned[i] != '\0' && line_cleaned[i] != ' ')
		i++;
	name = ft_strndup(line_cleaned, i);
	free(line_cleaned);
	return (name);
}

static int	find_redirection(char *line)
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

static void redirections(t_lines *lst_lines)
{
	int i;
	char *name;

	while (lst_lines)
	{
		i = 0;
		while ((i = find_redirection(lst_lines->line)) != -1)
		{
			lst_lines->line = ft_strdup("hui");
			// name = split_name(line + i);
			// if (name)
			// free(name);
			// name = split_name(line + i);
			// str1 = ft_strndup(line, i);
			// str2 = ft_strstr(line + i, name) + ft_strlen(name);
			// free(line);
			// line = ft_strjoin(str1, str2);
			// if (line[i + 1] == '>')
			// 	i++;
		}
		lst_lines = lst_lines->next;
	}
}

t_lines		*parse(char *line, t_lines **lst_lines)
{
	ft_printf("OK\n");
	int i;
	char *str;
	t_lines *elem;
	int input;
	
	i = 0;
	input = 0;
	while (line)
	{
		i = find_symbol(line);
		str = ft_strndup(line, i);
		elem = create_elem(str);
		add_to_end(lst_lines, elem);
		elem->input = input;
		if (line[i] == '|')
			input = create_pipe(elem);
		if (line[i] == ';')
			input = 0;
		if (line[i] == '\0')
			break;
		line = line + i + 1;
	}
	redirections(*lst_lines);
	if ((*lst_lines))
		print_data(*lst_lines);
	return (NULL);
}
