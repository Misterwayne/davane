#ifndef MINISHELL_H
# define MINISHELL_H

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

typedef struct	s_var
{
	char 	**var;
	int		nb_var;
}				t_var;

typedef struct	s_env
{
	char 	**var;
	int		nb_var;
}				t_env;

char	**ft_split(char const *s, char c);
char     *pwd(void);

#endif