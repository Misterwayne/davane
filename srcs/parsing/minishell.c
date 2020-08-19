/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:15:21 by truepath          #+#    #+#             */
/*   Updated: 2020/08/19 15:09:48 by mwane            ###   ########.fr       */
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

void		lsh_loop(t_shell *shell)
{
	char *line;
	char **args;
	int red;
	int on;
	int i;

	i = 0;
	on = 0;
	while (on == 0)
	{
		print_promt();
		red = get_next_line(0, &line);	// premier parsing
		args = lsh_split_line(line);	//split the line by white space
		check_v(shell, args);			// this will check for '$' and replace the key by its value
		if (!(as_equal(shell, args[0]))) // check if the first argv as one equal and if so add the varible to the chaine list
		{
			i = check_commande(shell->cmd, args[0]);			//check if a word in the line correspond to a commande
			if (i >= 0 && i < 6)
				launch(shell, i, args);				// if yes, launch that commande based on the index i
			else if (i == 6)
				on = 1;
			else
				ft_printf("Minishell : Commande not found : %s\n",args[0]);
		}
		free(args);
	}
	free(line);
}

int		main(int argc, char **argv, char **env)
{
	/*
	Using a array of pointer to funcion is better than running the binary of our functions,and i think its the real way to do this project.
	We shouldn't use a text file to save our environemt varialble, nobody doest it in their minishell, a chained list is probably better.
	The list of env variable that we need is listed here "http://manpagesfr.free.fr/man/man1/bash.1.html"


	">>" put the argument into a file like "argv >> file"
	">" is the same
	"=" does weird shit
	cd does weird shit
	*/
	t_env envi; // struct qui contient les variables
	t_var *var;	// chained list struct for the variables
	t_cmd cmd; // contient la liste des commandes
	t_shell shell;	// global struct zith all the other in it

	var = new_node("0=0");		// init the chained list, the element "0=0" will always be the last;
	cmd.cmd_lst = malloc(sizeof(char*) * 20);
	load_env(&envi);
	load_cmd(&cmd);
	shell.cmd = &cmd;
	shell.var = var;
	lsh_loop(&shell);
	return (0);
}