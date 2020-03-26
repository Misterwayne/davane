/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:13:52 by mwane             #+#    #+#             */
/*   Updated: 2019/10/10 16:03:54 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*psrc;
	size_t			i;
	unsigned char	*pdest;

	i = 0;
	pdest = (unsigned char*)dest;
	psrc = (unsigned char*)src;
	if ((!dest && !src) || !size)
		return (dest);
	if (psrc < pdest)
		while (++i <= size)
			pdest[size - i] = psrc[size - i];
	else
		while (size-- > 0)
			*(pdest++) = *(psrc++);
	return (dest);
}
