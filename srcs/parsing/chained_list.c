
#include <stdio.h>
#include <stdlib.h>
char	**ft_split(char const *s, char c);

typedef struct	s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

void	ft_put_data(char *data, t_env *elem)
{
	int 	i;
	char	**split;

	i = 0;
	split = ft_split((const char *)data, '=');
	elem->key = split[0];
	elem->value = split[1];
	elem->next = NULL;
	// printf("%s : %s\n", elem->key, elem->value);
}

t_env	*ft_create_elem(char *data)
{
	t_env	*elem;

	elem = malloc(sizeof(t_env));
	ft_put_data(data, elem);
	return(elem);
}

void	find_end(t_env *beg, t_env *new)
{
	t_env tmp;
	
	tmp = *beg;
	while(tmp.next != 0)
	{
		tmp = *tmp.next;
	}
	tmp = *new;
}


void	ft_create_list(char **env)
{
	t_env	*begin_list;
	t_env	*new;
	void	*l;
	int i;

	i = 1;
	begin_list = ft_create_elem(env[0]);
	while (env[i])
	{

		new = ft_create_elem(env[i]);
		new->next = begin_list;
		find_end(begin_list, new);
		i++;
	}
	new = begin_list;
	while (new != NULL)
	{
		printf("%s:%s",new->key,new->value);
		new = new->next;
	}

}

int main(int argc, char **argv, char **env)
{
	int i;
	i = 0;

	ft_create_list(env);
	return(0);
}
