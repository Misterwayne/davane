/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:29:20 by truepath          #+#    #+#             */
/*   Updated: 2020/10/17 15:43:55 by davlasov         ###   ########.fr       */
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
#include <sys/errno.h>


/*
We need a struc that will hold all of the environment variable.
we also need a struct that will hold the argv of the commands.
maybe a chained list for the yet to be exported variables.
we need an array of function for our bulltin.
*/

typedef struct	s_shell t_shell;

typedef struct lines
{
	char			*line;
	char			**argv;
	char			*symbol;
	char			*cmd;
	struct lines	*next;
}				t_lines;

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*prev;
	struct s_env	*next;
}					t_env;

typedef struct 		s_local
{
	char			*key;
	char			*value;
	struct s_local	*prev;
}					t_local;


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
	t_local		*local;
	char		**enviro;
	char		*current_pwd;
	char		*usr;
	int			last_pid;
	int			last_return;
	int			var_flags;
}				t_shell;


// PARSING FUNCTIONS

char			**lsh_split_line(char *line);
char			**ft_split(char const *s, char c);
char			*get_value(t_env *env, char *line);
int     		check_commande(t_cmd *cnd, char *line);
int				parsing_line(t_shell *shell, char **args);
void     		check_v(t_shell *shell, char **args);
char			*ft_strndup(char *str, int n);
char			**split_$(char *line);	//check if one of the arguments stat with '$' and if yes replace it by its value
int     		get_$(char *s, char *res, int i);




// MINISHELL CORE

void			lsh_loop(t_shell *shell);				//main function
int 			launch(t_shell *shell, int index, char **argv);	//Where we launch everything
void    		load_cmd(t_cmd *cmd);					//	init the cmd struct
int				add_var(char *line, t_shell *shell);	// ad variable to the env
int				load_env(char **env, t_shell *shell);					// init the env struct
void			print_promt(void);						// print the promt
char 			*add_path(t_shell *shell,char **args);

// BUILTIN

int     cd(char **argv, t_shell *shell);			// this one works but some errors are still possible
int     export(char **argv, t_shell *shell);		//this function needs to stock the variable inside the chained list
int 	echo(char **argv, t_shell *shell);			//it needs to be able to print an env variable from a key
int 	env(char **argv, t_shell *shell);			//i don't know yet
int		unset(char **argv, t_shell *shell);			//it needs to pop a variable from the chained list
int     pwd(char **argv, t_shell *shell);			//this one works too
int		ft_exit(char **argv, t_shell *shell);		//this will need to  be able to free anything still allocated


// PARSE
int		is_special_symbol(char *str);
void	parse_functions(t_shell *shell, char *line);
int     launch_body(t_shell *shell, t_lines *fun);
int   	launch_exec(t_shell *shell, char **args, int input, int output);
void	semicolon(t_shell *shell, t_lines *fun, int input, int output);
int		ft_pipe(t_shell *shell, t_lines *fun, int input);
int     ft_redirection(t_shell *shell, t_lines *fun);
int     ft_back_redirection(t_shell *shell, t_lines *fun);
char        *replace_line(t_shell *shell, char *line);

// SIGNAL_FUNCTION

void    catch_signal(int sig);
void    signal_handling(void);

#endif
