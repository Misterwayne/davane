/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:05:22 by mwane             #+#    #+#             */
/*   Updated: 2019/10/10 16:03:59 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memset(void *s, int c, size_t size)
{
	unsigned char *str;

	str = (unsigned char*)s;
	while (size-- > 0)
		*(str++) = (unsigned char)c;
	return (s);
}
