/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:52:37 by mwane             #+#    #+#             */
/*   Updated: 2019/10/16 19:35:01 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, unsigned int len)
{
	unsigned int	j;
	unsigned int	i;

	j = 0;
	i = 0;
	if (to_find[j] == '\0')
		return (str);
	while (*str && i < len)
	{
		j = 0;
		while (str[j] == to_find[j] && str[j] && i < len)
		{
			if (to_find[j + 1] == '\0')
				return (str);
			j++;
			i++;
		}
		str++;
		i++;
	}
	return (NULL);
}
