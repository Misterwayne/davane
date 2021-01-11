
#include <stdio.h>
#include <stdlib.h>
#include "../../headers/minishell.h"

char	*ft_name(char *s)
{
	char	**tmp;
	char	*name;
	int 	i;

	if (!(tmp = ft_split(s, '=')))
		return (NULL);
	name = tmp[0];
	i = 1;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (name);
}

void 	ft_clean_elem(t_env	**env)
{
	if (!(env))
		return ;
	if ((*env)->key)
		free((*env)->key);
	if ((*env)->value)
		free((*env)->value);
	(*env)->key = NULL;
	(*env)->value = NULL;
	free(*env);
	*env = NULL;
}

t_env	*ft_create_elem(char *data)
{
	t_env	*elem;
	char	**split;

	elem = malloc(sizeof(t_env));
	elem->key = ft_name(data);
	if (!(elem->key ) || !(ft_strchr(data, '=')))
		elem->value = NULL;
	else
		elem->value = ft_strdup(ft_strchr(data, '=') + 1);
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
	shell->env = begin_list;
	shell->enviro = env;
	return(0);
}
