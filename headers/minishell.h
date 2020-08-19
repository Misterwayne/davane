/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:29:20 by truepath          #+#    #+#             */
/*   Updated: 2020/08/19 18:35:25 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define ADD_VAR 1
# define CMD_FOUND 2
# define ERROR -1

#include <unistd.h>
#include "../srcs/parsing/gnl/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "header.h"


/*
We need a struc that will hold all of the environment variable.
we also need a struct that will hold the argv of the commands.
maybe a chained list for the yet to be exported variables.
we need an array of function for our bulltin.
*/

typedef struct	s_shell t_shell;

typedef struct	s_var								//this is a first in, last out chained list
{
	char 				*key;						//the key to the var
	char				*value;						//the value of the var						
	struct s_var		*next;
	struct s_var		*prev;
	struct s_var		*first;
}				t_var;

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}				t_env;

typedef struct  s_cmd
{
	char		**cmd_lst;								//the list of command that zill be used later as key for builtin_array
	char		**argvs;								//2d array for the arguments of the builtin
	char		*path;										
	int			(*builtin_array[8])(char **argv, struct s_shell *shell);		//array of pointer to function 
}				t_cmd;

typedef struct	s_shell
{
	t_cmd		*cmd;
	t_env		*env;
	t_var		*var;
	int			var_flags;
}				t_shell;


// PARSING FUNCTIONS

char			**lsh_split_line(char *line);
char			**ft_split(char const *s, char c);
char			*get_value(t_env *env, char *line);
int     		check_commande(t_cmd *cnd, char *line);
int				parsing_line(t_shell *shell, char **args);
int     		check_var(char *line, t_var *var, t_env *env);
char     		*check_v(t_shell *shell, char **args);		//check if one of the arguments stat with '$' and if yes replace it by its value
int         	is_a_var(t_shell *shell, char *line);		//check if line contains one '=', if so, it becomes a variable declaration

// CHAINED LIST FUNCTION

t_var        	*new_node(char *line);				//creat a new node
t_var        	*new_var(t_var *var, char *line);	//add a node to the list
void         	print_chainedlist(t_var *var);		// print the chained list
int     	 	is_in_list(t_var *var, char *line); //check if line is a key in the chained list
void    	 	replace_var(t_var *var, char* line);//replace the value of a node by linne



// MINISHELL CORE

void			lsh_loop(t_shell *shell);				//main function
int 			launch(t_shell *shell, int index, char **argv);	//Where we launch everything
void    		load_cmd(t_cmd *cmd);					//	init the cmd struct
int				add_var(char *line, t_shell *shell);	// ad variable to the env
int				load_env(t_env *env);					// init the env struct
void			print_promt(void);						// print the promt

// BUILTIN

int     cd(char **argv, t_shell *shell);			// this one works but some errors are still possible
int     export(char **argv, t_shell *shell);		//this function needs to stock the variable inside the chained list
int 	echo(char **argv, t_shell *shell);			//it needs to be able to print an env variable from a key
int 	env(char **argv, t_shell *shell);			//i don't know yet
int		unset(char **argv, t_shell *shell);			//it needs to pop a variable from the chained list
int     pwd(char **argv, t_shell *shell);			//this one works too
int		ft_exit(char **argv, t_shell *shell);		//this will need to  be able to free anything still allocated

#endif