/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:15:21 by truepath          #+#    #+#             */
/*   Updated: 2020/09/06 16:38:37 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		print_promt(shell);
		red = get_next_line(0, &line);
		if (line[0] != '\0')
		{
		// premier parsing
			args = lsh_split_line(line);	//split the line by white space
			//check_v(shell, args);			// this will check for '$' and replace the key by its value
			if (!(is_a_var(shell, args[0]))) // check if the first argv as one equal and if so add the varible to the chaine list
			{
				i = check_commande(shell->cmd, args[0]);		//check if a word in the line correspond to a commande
				// if (i >= 0 && i < 6)
				// 	launch(shell, i, args);				// if yes, launch that commande based on the index i
				// else if (i == 6)
				// 	on = 1;
				// else
				//launch_bin(shell, args, 0);
				parse_functions(shell, line);
				//ft_printf("Minishell : Commande not found : pid = %d return = %d\n",shell->last_pid,shell->last_return);
			}
			free(args);
		}
		free(line);
	}
	free(line);
}

void	get_pwd(t_shell *shell)
{
	int		j;
	char	*path;

	j = 0;
	path = malloc(sizeof(char) * 1024);
	getwd(path);
	j = ft_strlen(path);
	while (path[j] != '/')
		j--;
	shell->current_pwd = (path + (j + 1));
}

void	get_usr(t_shell *shell, char **env)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (env[i])
    {
        if (ft_strncmp(env[i],"USER",4) == 0)
            break;
        i++;
    }
	j = ft_strlen(env[i]);
	while (env[i][j] != '=')
		j--;
	shell->usr = (env[i] + (j + 1));
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

	To do:
	Solving the probleme $variable=value (expected :$maick=loki res : pili=loki)
										(current :$maick=loki) res : new var $maick=loki
	-Bulitin		
		Export
		Unset
		env

	- (Done)integrating the binaries (cat,mkdir,etc..)

	- ">>" and ">" redirection

	- "|" pipes 

	- "$?"

	-"ctrl -C" "ctrl -D" "ctrl -\"
	*/
	t_env envi; 	// chained list for environnement variable
	t_var *var;		// chained list struct for the variables
	t_cmd cmd; 		// contient la liste des commandes
	t_shell shell;	// global struct with all the other in it

	var = new_node("0=0");		// init the chained list, the element "0=0" will always be the last;
	cmd.cmd_lst = malloc(sizeof(char*) * 20);
	load_env(env, &shell);
	load_cmd(&cmd);
	shell.cmd = &cmd;
	shell.var = var;
	shell.enviro = env;
	get_pwd(&shell);
	get_usr(&shell, env);
	lsh_loop(&shell);
	return (0);
}
