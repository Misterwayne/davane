void lsh_loop(t_shell *shell)	
{
			args = lsh_split_line(line);	//split the line by white space
			if (!(is_a_var(shell, args[0]))) // check if the first argv as one equal and if so add the varible to the chaine list
			{
				//i = check_commande(shell->cmd, args[0]);		//check if a word in the line correspond to a commande
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
