
#include "../../headers/minishell.h"

// int		is_even_quotes(char *line) // am I using it?
// {
// 	int i;
// 	int n;

// 	n = 0;
// 	i = 0;

// 	while (line[i] != '\0')
// 	{
// 		if (line[i] == '"')
// 			n++;
// 		i++;
// 	}
// 	if (n % 2 == 0)
// 		return (0);
// 	return (1);
// }

// char	*quotes(char *line) // am I using it?
// {
// 	char	*line2;

// 	while (is_even_quotes(line) != 0)
// 	{
// 		ft_printf(">");
// 		line = ft_strjoin(line, "\n");
// 		if (get_next_line(0, &line2) > 0)
// 			line = ft_strjoin(line, line2);
// 	}
// 	return (line);
// }

char *protect_quotes(char *line)
{
	int i;
	char *str1;
	char *str2;
	char *symbol;

	i = 0;

	while (line[i] != '\0')
	{	
		if (line[i] == '\'' || line[i] == '\"')
			{
				str1 = strndup(line, i);
				str2 = ft_strjoin("\\", line + i);
				free(line);
				line = ft_strjoin(str1, str2);
				i++;
			}
		i++;
	}
	return (line);
}

char 	*delete_quotes(char *line)
{
	int i;
	int j;
	char symbol;
	char *copy;

	i = 0;
	j = 0;
	copy = malloc(ft_strlen(line));
	symbol = 0;
	while (line[i] != '\0')
	{	
		if (line[i] == '\\')
			{
				copy[j++] = line[i + 1];
				i = i + 2;
			}
		else if ((line[i] == '\'' || line[i]== '\"') && symbol == 0)
			{
				symbol = line[i];
				i++;
			}
		else if (line[i] == symbol)
			{
				symbol = 0;
				i++;
				continue ;
			}
		else
			copy[j++] = line[i++];
	}
	copy[j] = '\0';
	free(line);
	return (copy);
}


char    **quotes(t_shell *shell, char **argv)
{
	int i;

    i = 0;
    while (argv[i])
    {
        argv[i] = delete_quotes(argv[i]);
        i++;
    }
    return (argv);
}
