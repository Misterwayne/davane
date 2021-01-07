#include "../../headers/minishell.h"

char	*ft_strndup(char *str, int n)
{
	char	*str_new;
	int		i;

	i = ft_strlen(str);
	if (i > n)
		i = n; 
	if (!(str_new = malloc((sizeof(char) * (i + 1)))))
		return (NULL);
	i = 0;
	while (str[i] && i < n)
		{
			str_new[i] = str[i];
			i++;
		}
	str_new[i] = '\0';
	return (str_new);
}
