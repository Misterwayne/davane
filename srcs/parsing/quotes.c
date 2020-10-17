
#include "../../headers/minishell.h"

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

char	*quotes(char *line)
{
	char	*line2;

	while (is_even_quotes(line) != 0)
	{
		ft_printf(">");
		line = ft_strjoin(line, "\n");
		if (get_next_line(0, &line2) > 0)
			line = ft_strjoin(line, line2);
	}
	return (line);
}
