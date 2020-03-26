#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include "../srcs/gnl/get_next_line.h"
#include <string.h>
#include <fcntl.h>
#include <stdio.h>

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

char			**ft_split(char const *s, char c);
void			print_promt(void);
int 			launch(char *prog, char **argv);
void    		load_cmd(t_cmd *cmd);
char   			*pwd(void);
void			lsh_loop(void);
char			*get_value(t_env *env, char *line);
int				check_var(char *line, t_var *var, t_env *env);
int     		check_commande(t_cmd *cmd, char *line);

#endif