#include "../headers/minishell.h"
#include "gnl/get_next_line.h"

char	**lsh_split_line(char *line)
{
	char **tockens;

	tockens = ft_split(line, ' ');
	return(tockens);
}

void	lsh_loop(void)
{
	char *line;
	char **args;
	int red;

	write (1, ">", 1);
	red = get_next_line(1, &line);
	args = lsh_split_line(line);
	free(line);
	free(args);
}

int		main(int argc, char **argv)
{
	lsh_loop();
	return (0);
}