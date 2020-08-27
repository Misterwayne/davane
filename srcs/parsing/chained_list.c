
#include <stdio.h>
#include <stdlib.h>
#include "../../headers/minishell.h"

char	**ft_split_env(char *s)
{
	char	**split;
	char	*s_copy;
	int i;

	i = 0;
	s_copy = ft_strdup((const char *)s);
	split = malloc(sizeof(char *)* 2);
	while (s_copy[i] != '\0')
	{
		if (s_copy[i] == '=')
		{
			s_copy[i] = '\0';
			split[0] = ft_strdup((const char *)s_copy);
			split[1] = ft_strdup((const char *)&(s_copy[i + 1]));
			return (split);
		}
		i++;
	}
	free (s_copy);
	return(0);
}

t_env	*ft_create_elem(char *data)
{
	t_env	*elem;
	int 	i;
	char	**split;

	elem = malloc(sizeof(t_env));
	split = ft_split_env(data);
	elem->key = split[0];
	elem->value = split[1];
	elem->prev = NULL;
	elem->next = NULL;
	return(elem);
}

t_env	*put_to_the_end(t_env *list, char *data)
{
	t_env	*tmp;
	t_env	*beginin;
	
	if (!(list))
	{
		list = ft_create_elem(data);
		return(list);
	}
	else
	{
		tmp = ft_create_elem(data);
		beginin = list;
		while(list->next)
			list = list->next;
		tmp->prev = list;
		list->next = tmp;
		return(beginin);
	}
}


int		load_env(char **env, t_shell *shell)
{
	t_env	*begin_list;
	int		i;
	
	i = 0;
	begin_list = NULL;
	while(env[i])
	{
		begin_list = put_to_the_end(begin_list, env[i]);
		i++;
	}
	i = 0;
	shell->env = begin_list;
	return(0);
}
