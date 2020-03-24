#include "../../headers/minishell.h"
#include "gnl/get_next_line.h"
#include <string.h>

char	**lsh_split_line(char *line)
{
	char **tockens;

	tockens = ft_split(line, ' ');
	return(tockens);
}

void	print_promt(void)// affiche la prompt
{
	char *prompt;

	prompt = "|Minishell| ";
	write(1, prompt, ft_strlen(prompt));
	write(1, ">> :", 3);
	return ;
}

int		check_command(char *line, t_var *var)
{
	int i;
	int fd;

	i = 0;
	if (!(fd = open("var.txt", O_RDWR | O_CREAT | O_APPEND, 00700)))
        		return (1);
	while (line[i])// ecrit les variables shell dans une struct et dans un fichier txt
	{			   // uniquement si un espace est present dans la string
		if (line[i] == '=' && var->nb_var < 20)
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			var->var[var->nb_var] = strdup(line);
			var->nb_var += 1;
			close(fd);
			return (0);
		}
		i++;
	}
	close(fd);
	return (1);
}

void	lsh_loop(void)
{
	char *line;
	char **args;
	t_var vars; // struct qui contient les variables
	int red;
	int on;

	on = 0;
	vars.var = malloc(sizeof(char*) * 20);
	vars.nb_var = 0;
	while (on == 0)
	{
		print_promt();
		red = get_next_line(0, &line);
		check_command(line, &vars); // premier parsing
		args = lsh_split_line(line);
	}
	free(line);
}

int		main(int argc, char **argv)
{
	lsh_loop();
	return (0);
}