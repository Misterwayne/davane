#include "../../headers/minishell.h"

char	*get_pwd(void)
{
	int		j;
	char	*path;

	j = 0;
	path = malloc(sizeof(char) * 1024);
	getwd(path);
	j = ft_strlen(path);
	while (path[j] != '/')
		j--;
	return (path + (j + 1));
}

char	**lsh_split_line(char *line)
{
	char **tockens;

	tockens = ft_split(line, ' ');
	return(tockens);
}

void	print_promt(void)// affiche la prompt
{
	char *pwd;

	pwd = get_pwd();
	write(1, "\x1b[32m", 6);// Green
	write(1, "-> ", 3);
	write(1, "\x1b[34m", 6); // blue
	write(1, "(", 1);
	write(1, "\x1b[31m", 6); // RED
	write(1, pwd, ft_strlen(pwd));
	write(1, "\x1b[34m", 6);
	write(1, ") ", 2);
	write(1, "\x1b[36m", 6);
	write(1, "minishell", ft_strlen("minishell"));
	write(1, " :", 2);
	write(1, "\x1b[0m", 5); // reset
	return ;
}

