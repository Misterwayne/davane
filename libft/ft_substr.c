/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:50:03 by startne           #+#    #+#             */
/*   Updated: 2019/10/18 13:31:47 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char		*newstr;
	size_t		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(newstr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (ft_strlen((char *)s) < (int)start)
	{
		*newstr = '\0';
		return (newstr);
	}
	while (s[start] && i + 1 <= len)
	{
		newstr[i++] = s[start++];
	}
	newstr[i] = '\0';
	return (newstr);
}
