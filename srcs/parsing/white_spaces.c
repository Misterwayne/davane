#include "../../headers/minishell.h"

int		skip_white_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			return (i);
		i++;
	}
	return (i);
}

int		is_even_quotes(char *line)
{
	int i;
	int n;

	n = 0;
	i = 0;

	while (line[i] != '\0')
	{
		if (line[i] == '"')
			n++;
		i++;
	}
	if (n % 2 == 0)
		return (0);
	return (1);
}

char	*delete_spaces(char *line)
{
	char *str;
	char *str_new;
		
	int i;
	int j;

	i = 0;
	j = 0;
	str = line;
	str_new = malloc(ft_strlen(str) + 1);
	i = i + skip_white_spaces(str + i);
	while (str[i] != '\0')
	{
		if (str[i] == '"')
		{
			str_new[j++] = str[i++];
			while (str[i] != '\0')
			{
				str_new[j++] = str[i++];
				if (str[i] == '"')
					break;
			}
			if (str[i] == '\0')
				break;
		}
		str_new[j] = str[i];
		i++;
		if (str_new[j] == ' ')
		{
			i = i + skip_white_spaces(str + i);
			if (str[i] == '\0')
				break;
		}
		j++;
	}
	str_new[j] = str[i];
	return (str_new);
	//ft_printf("%s", str_new);
}


void	delete_endspaces(char *line)
{
	char *str;
	char *str_new;
		
	int i;
	int j;

	i = 0;
	j = 0;
	str = line;
	i = i + skip_white_spaces(str + i);
	str_new = malloc(ft_strlen(str) - i + 1);
	while (str[i] != '\0')
	{
		str_new[j++] = str[i++];
		i++;
		if (str_new[j] == ' ')
		{
			i = i + skip_white_spaces(str + i);
			if (str[i] == '\0')
				break;
		}
		j++;
	}
	str_new[j] = str[i];
	free(line);
	line = str_new;
}

void	split_on_arguments(t_fun *fun)
{
	int i;

	while(fun)
	{
		// i = 0;
		fun->argv = ft_split(fun->line, ' ');
		// while (fun->argv[i])
		// 	ft_printf("%s ", fun->argv[i++]);
		delete_endspaces(fun->line);
		if (!(fun->next))
			return ;
		fun = fun->next;
	}
}
