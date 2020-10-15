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

void	split_line(t_fun *fun)
{
	char *str;
	char *str_new;
		
	int i;
	int j;

	i = 0;
	j = 0;
	str = fun->line;
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
	free(fun->line);
	fun->line = str_new;
	//ft_printf("%s", str_new);
	//fun->argv = ft_split(str_new, ' ');
}

void	split_on_arguments(t_fun *fun)
{
	int i;

	while(fun)
	{
		split_line(fun);
		// i = 0;
		// while (fun->argv[i])
		// 	ft_printf("%s ", fun->argv[i++]);
		if (!(fun->next))
			return ;
		fun = fun->next;
	}
}
