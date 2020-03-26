/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:52:04 by mwane             #+#    #+#             */
/*   Updated: 2019/10/16 19:06:02 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	ldest;
	unsigned int	lsrc;

	i = 0;
	j = 0;
	ldest = ft_strlen(dest);
	lsrc = ft_strlen(src);
	i = ldest;
	if (ldest >= size)
		return (lsrc + size);
	size = size - ldest - 1;
	while (src[j])
	{
		if (size--)
			dest[i++] = src[j++];
		else
			break ;
	}
	dest[i] = '\0';
	return (ldest + lsrc);
}
