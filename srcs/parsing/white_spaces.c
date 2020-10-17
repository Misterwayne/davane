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
