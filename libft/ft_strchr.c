/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 17:19:01 by mwane             #+#    #+#             */
/*   Updated: 2019/10/10 16:02:32 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if ((char)c == *str)
			return ((char*)str);
		str++;
	}
	if (c == '\0')
		return ((char*)str);
	return (NULL);
}
