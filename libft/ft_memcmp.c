/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:09:55 by mwane             #+#    #+#             */
/*   Updated: 2019/10/10 16:03:21 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t size)
{
	unsigned char	*pstr1;
	unsigned char	*pstr2;

	pstr1 = (unsigned char *)str1;
	pstr2 = (unsigned char *)str2;
	while (size-- > 0)
	{
		if (*pstr1 != *pstr2)
			return (*pstr1 - *pstr2);
		pstr1++;
		pstr2++;
	}
	return (0);
}
