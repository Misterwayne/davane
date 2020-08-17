/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:15:21 by truepath          #+#    #+#             */
/*   Updated: 2020/08/17 15:27:14 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

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

int		load_env(t_env *env)
{
	return (0);
}

char	*get_value(t_env *env, char *line)
{
	return NULL;
}

int		check_var(char *line, t_var *var, t_env *env)
{
	return (1);
}

void		lsh_loop(void)
{
	char *line;
	char **args;
	t_var vars;
	t_env env; // struct qui contient les variables
	t_cmd cmd; // contient la liste des commandes
	t_shell shell;
	int red;
	int on;
	int i;

	i = 0;
	on = 0;
	cmd.cmd_lst = malloc(sizeof(char*) * 20);
	env.nb_var = 0;
	shell.cmd = &cmd;
	load_env(&env);
	load_cmd(&cmd);
	while (on == 0)
	{
		print_promt();
		red = get_next_line(0, &line);
		write(1, "Da !\n", ft_strlen("Da !\n")); // premier parsing
		args = lsh_split_line(line);		//split the line by white space
		i = check_commande(&cmd, args[0]);
		if (i < 6)		//check if a word in the line correspond to a commande
			launch(&shell, i, args);				// if yes, launch that commande
		else if (i == 6)
			on = 1;
		else
			ft_printf("Minishell : Commande not found : %s\n",args[0]);
		free(args);
	}
	free(line);
}

int		main(int argc, char **argv)
{
	/*
	Using a array of pointer to funcion is better than running the binary of our functions,and i think its the real way to do this project.
	We shouldn't use a text file to save our environemt varialble, nobody doest it in their minishell, a chained list is probably better.
	The list of env variable that we need is listed here "http://manpagesfr.free.fr/man/man1/bash.1.html" 
	*/
	lsh_loop();
	return (0);
}