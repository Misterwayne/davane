/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:29:20 by truepath          #+#    #+#             */
/*   Updated: 2020/08/16 14:41:25 by mwane            ###   ########.fr       */
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
	char 		**var;
	int			nb_var;
}				t_var;

typedef struct	s_env
{
	char 		**var;
	int			nb_var;
}				t_env;

typedef struct  s_cmd
{
	char		**cmd_lst;
	char		*path;
}				t_cmd;

typedef struct	s_shell
{
	t_cmd		*cmd;
	t_env		*env;
	t_var		*var;
	int			var_flags;
}				t_shell;

char			**ft_split(char const *s, char c);
void			print_promt(void);
int 			launch(char *prog, char **argv);
void    		load_cmd(t_cmd *cmd);
char   			*pwd(void);
void			lsh_loop(void);
char			*get_value(t_env *env, char *line);
int				add_var(char *line, t_shell *shell);
int     		check_commande(t_cmd *cnd, char *line);
int     		check_var(char *line, t_var *var, t_env *env);
int				parsing_line(t_shell *shell, char **args);
int				load_env(t_env *env);
char			**lsh_split_line(char *line);

#endif