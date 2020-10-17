#include "../../headers/minishell.h"
void	get_pwd(t_shell *shell);

char	**lsh_split_line(char *line)
{
	char **tockens;

	tockens = ft_split(line, ' ');
	return(tockens);
}

void	print_promt(t_shell *shell)// affiche la prompt
{
	char *prompt;

	get_pwd(shell);
	write(1, "\x1b[32m", 6);// Green
	write(1, "-> ", 3);
	write(1, "\x1b[34m", 6); // blue
	write(1, "(", 1);
	write(1, "\x1b[31m", 6); // RED
	write(1, shell->usr, ft_strlen(shell->usr));
	write(1, "\x1b[34m", 6);
	write(1, ") ", 2);
	write(1, "\x1b[36m", 6);
	write(1, shell->current_pwd, ft_strlen(shell->current_pwd));
	write(1, " :", 2);
	write(1, "\x1b[0m", 5); // reset
	return ;
}

