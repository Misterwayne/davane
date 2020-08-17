/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:29:20 by truepath          #+#    #+#             */
/*   Updated: 2020/08/17 14:54:31 by mwane            ###   ########.fr       */
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

typedef struct	s_var
{
	char 		*key;						//the key to the var
	char		*value;						//the value of the var
	int			index;
	struct s_var		*next;						//begining of the chained list
	struct s_var		*prev;
	struct s_var		*first;
}				t_var;

typedef struct	s_env
{
	struct t_var		*first;						//pointer to the first node of the chained list
	char		*path;						//the current path
	int			nb_var;						//the total number of varariable in the env
}				t_env;

typedef struct  s_cmd
{
	char		**cmd_lst;									//the list of command that zill be used later as key for builtin_array
	char		**argvs;									//2d array for the arguments of the builtin
	char		*path;										
	int			(*builtin_array[8])(char **argv);		//array of pointer to function 
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

// MINISHELL CORE

void			lsh_loop(void);
int 			launch(t_shell *shell, int index, char **argv);
void    		load_cmd(t_cmd *cmd);
int				add_var(char *line, t_shell *shell);
int				load_env(t_env *env);
void			print_promt(void);

// BUILTIN

int     cd(char **argv);
int     export(char **argv);
int 	echo(char **argv);
int 	env(char **argv);
int		unset(char **argv);
int     pwd(char **argv);

#endif