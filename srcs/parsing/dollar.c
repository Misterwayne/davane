
#include "../../headers/minishell.h"

char *get_value(t_env *env, char *key)
{
	while(env)
    {
		if (ft_strcmp(env->key, key) == 0)
	   		return (env->value);
		env = env->next;
    }
	return (NULL);
}

char *get_key(char *line)
{
	char	*str;
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != ' ' && line[i] != '\'' && line[i] != '\"' && line[i] != '$')
		i++;
	if (i == 0 && line[0] == '$') // PID
		return (ft_strdup("$$"));
	else if (i == 0)
		return (NULL);
	str = ft_strndup(line, i);
	return (str);
}


char *left_part(char *line, int i, t_env *env)
{
	char *str1;
	char *str2;
	char *var;
	char *key;
	char *new;
	int n;

	n = 0;
	if (!(key = get_key(line + i + 1)))
		return (ft_strndup(line, i + 1));
	if (ft_strcmp(key, "$$") == 0) // PID
		return (ft_strdup("PID"));
	if (ft_strcmp(key, "?") == 0)
		return (ft_strdup("RETURN")); // LAST RETURN
	if (!(var = get_value(env, key)))
		{
			free(key);
			return (ft_strndup(line, i));
		}
	else
		str2 = ft_strdup(var);
	str1 = ft_strndup(line, i);
	new = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (new);
}

char *right_part(char *line)
{
	char	*str;
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != ' ' && line[i] != '\'' && line[i] != '\"' && line[i] != '$')
		i++;
	str = ft_strdup(line + i);
	return (str);
}

char	 *dollar(char *line, t_env *env)
{
	int i;
	char symbol;
	char *str1;
	char *var;
	char *str2;

	i = 0;
	symbol = 0;
	while (line[i] != '\0')
	{	
		if (line[i] == '$' && symbol != '\'')
			{
				str1 = left_part(line, i, env);
				str2 = right_part(line + i + 1);
				i = ft_strlen(str1);
				free(line);
				line = ft_strjoin(str1, str2);
				free(str1);
				free(str2);
				continue;
			}
		if ((line[i] == '\'' || line[i]== '\"') && symbol == 0)
			symbol = line[i];
		else if (line[i] == symbol && symbol != 0)
			symbol = 0;
		i++;
	}
	return (line);
}
