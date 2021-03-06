#include <stdlib.h>
#include <stdio.h>
#include "../../headers/minishell.h"

int		ft_strlen_split2(char *s, char *res)
{
	// int i;

	// i = 0;
	// if (s[i] == '$')
	// 	return (get_dollar(s, res, i));
	// while (s[i] != '$' && *s != '\0') 
	// {
	// 	res[i] = s[i];
	// 	i++;
	// }
	// res[i] = '\0';
	return (0);
}

int		ft_strcount2(char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == ' ' || s[i] == '=')
			n++;
		i++;
	}
	return (n);
}

char	**split_dollar(char *str)
{
	char  	**res;
	int		i;
	int		o;
	int		len;

	i = 0;
	o = 0;
	len = ft_strcount2(str, '$');
	if(!(res = malloc(sizeof(char *) * len + 1)))
		return (0);
	while (i < len)
	{
		res[i] = malloc(sizeof(char) * 20);
		o += ft_strlen_split2((str + o), res[i]);
		i++;
	}
	res[i] = NULL;
	return res;
}
