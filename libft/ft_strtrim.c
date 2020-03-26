/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:34:24 by mwane             #+#    #+#             */
/*   Updated: 2019/10/18 13:29:15 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int					lstrlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int					is_in_set(char c, char const *set)
{
	int i;

	i = -1;
	if (set == NULL)
		return (0);
	while (set[++i])
	{
		if (c == set[i])
			return (1);
	}
	return (0);
}

static unsigned int			count_trimed(char const *s1, char const *set)
{
	int				i;
	unsigned int	len_str;

	i = 0;
	len_str = lstrlen((char *)s1);
	while (is_in_set(s1[i++], set) && s1[i])
		len_str--;
	i = lstrlen((char *)s1) - 1;
	while (is_in_set(s1[i--], set) && i >= 0)
		len_str--;
	return (len_str);
}

char						*ft_strtrim(char const *s1, char const *set)
{
	char				*newstr;
	int					i;
	unsigned int		len_str;

	if (s1 == NULL)
		return (NULL);
	len_str = count_trimed(s1, set);
	if (!(newstr = malloc(sizeof(char) * len_str + 1)))
		return (NULL);
	i = 0;
	if (len_str != (unsigned int)lstrlen((char *)s1))
	{
		while (is_in_set(s1[i], set) && s1[i])
			i++;
	}
	len_str = 0;
	while (s1[i] && len_str < count_trimed(s1, set))
	{
		newstr[len_str++] = s1[i++];
	}
	newstr[len_str] = '\0';
	return (newstr);
}
