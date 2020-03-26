/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 12:38:45 by davlasov          #+#    #+#             */
/*   Updated: 2019/11/25 18:19:29 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0' && s[i] != '\n')
			i++;
	}
	return (i);
}

int			ft_find_n(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void		ft_fill(int len, char *str)
{
	int		i;

	i = 0;
	while (i < len + 1)
	{
		str[i] = '\0';
		i++;
	}
}

void		ft_memmove(char *dst, char *src, int len)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	while (i < len)
	{
		(dst[i] = '\0');
		i++;
	}
}

char		*ft_strjoin(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(new = malloc(len1 + len2 + 1)))
	{
		free(s1);
		return (0);
	}
	while (i < len1)
	{
		new[i] = s1[i];
		i++;
	}
	while (j < len2)
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}
