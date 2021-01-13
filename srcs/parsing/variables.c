
#include "../../headers/minishell.h"

char *change_variabe(char *line)
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
		if (line[i] == '$' && symbol != '\'')
			line[i] = 'D';
		if ((line[i] == '\'' || line[i]== '\"') && symbol == 0)
			symbol = line[i];
		else if (line[i] == symbol && symbol != 0)
			symbol = 0;
		i++;
	}
	//copy[j] = '\0';
	ft_printf("%s", line);
	//free(line);
	return (copy);
	
}
