/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:53:57 by mwane             #+#    #+#             */
/*   Updated: 2019/10/18 13:49:18 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	while (i >= 0)
	{
		if ((char)c == str[i])
			return ((char*)str + i);
		i--;
	}
	return (NULL);
}
