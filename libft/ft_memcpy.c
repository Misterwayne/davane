/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:03:15 by mwane             #+#    #+#             */
/*   Updated: 2019/10/10 16:03:50 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	unsigned char *psrc;
	unsigned char *pdest;

	if ((!dest && !src) || !size)
		return (dest);
	pdest = (unsigned char*)dest;
	psrc = (unsigned char*)src;
	while (size-- > 0)
		*(pdest++) = *(psrc++);
	return (dest);
}
