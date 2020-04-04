/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 16:29:20 by truepath          #+#    #+#             */
/*   Updated: 2020/04/04 18:16:03 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# define ADD_VAR 1
# define CMD_FOUND 2
# define ERROR -1

#include <unistd.h>
#include "../srcs/gnl/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "header.h"

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
void    		load_cmd(t_shell *shell);
char   			*pwd(void);
void			lsh_loop(void);
char			*get_value(t_env *env, char *line);
int				add_var(char *line, t_shell *shell);
int     		check_commande(t_shell *shell, char *line);
int     		check_var(char *line);
int				parsing_line(t_shell *shell, char **args);
int				load_env(t_shell *shell);
char			**lsh_split_line(char *line);

#endif