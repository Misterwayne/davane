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
		if (str[i] == ' ')
			{
				if (str[i + 1] == ' ')
					{
						i = i + skip_white_spaces(str + i);
						//ft_printf("%c, ", str[i]);
						str_new[j] = ' ';
						if (str[i] != '\0')
							j++;
						continue;
					}
			}
		str_new[j] = str[i];
		j++;
		i++;
	}
	str_new[j] = str[i];
	ft_printf("%s", str_new);
	fun->argv = ft_split(str_new, ' ');
}

void	split_on_arguments(t_fun *fun)
{
	int i;

	while(fun)
	{
		split_line(fun);
		//ft_printf("%s", fun->argv[0]);
		if (!(fun->next))
			return ;
		fun = fun->next;
	}
}
