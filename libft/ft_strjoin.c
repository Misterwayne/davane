/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:51:04 by mwane             #+#    #+#             */
/*   Updated: 2019/10/15 15:22:57 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		lens1;
	int		lens2;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	lens1 = ft_strlen((char *)s1);
	lens2 = ft_strlen((char *)s2);
	if (!(newstr = malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (NULL);
	while (++i < lens1)
		newstr[i] = s1[i];
	while (i < lens1 + lens2)
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}
