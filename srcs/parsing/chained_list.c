
#include <stdio.h>
#include <stdlib.h>
char	**ft_split(char const *s, char c);

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;


t_env	*ft_create_elem(char *data)
{
	t_env	*elem;
	int 	i;
	char	**split;

	elem = malloc(sizeof(t_env));
	split = ft_split((const char *)data, '=');
	elem->key = split[0];
	elem->value = split[1];
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
		list->next = tmp;
		return(beginin);
	}
}

int		main(int argc, char **argv, char **env)
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
	while(env[i])
	{
		printf("%s\n", begin_list->key);
		if (begin_list->next)
			begin_list = begin_list->next;
		i++;
	}
	return(0);
}
