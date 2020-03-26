/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:54:19 by mwane             #+#    #+#             */
/*   Updated: 2019/10/18 13:30:33 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int j;

	j = 0;
	if (to_find[j] == '\0' || to_find == NULL)
		return (str);
	while (*str != '\0')
	{
		j = 0;
		while (str[j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (str);
			j++;
		}
		str++;
	}
	return (0);
}
