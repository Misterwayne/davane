#include "../../headers/minishell.h"
char    *replace_line(t_env *env, char *line);

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
}

void	split_on_arguments(t_shell *shell, t_lines *lst_lines)
{
	while(lst_lines)
	{
		lst_lines->line = delete_spaces(lst_lines->line);
		lst_lines->line = replace_line(shell->env, lst_lines->line);
		lst_lines->argv = ft_split(lst_lines->line, ' ');
		check_v(shell, lst_lines->argv);
		if (!(lst_lines->next))
			break ;
		lst_lines = lst_lines->next;
	}
}
