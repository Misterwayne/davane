/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:19:30 by mwane             #+#    #+#             */
/*   Updated: 2019/10/10 16:05:27 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_strncmp(char *str1, char *str2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	while (i < n)
	{
		if (str1[i] == str2[i] && (str1[i] != '\0' || str2[i] != '\0'))
			i++;
		else
		{
			j += (unsigned char)str1[i] - (unsigned char)str2[i];
			if (j > 0)
				return (1);
			else if (j < 0)
				return (-1);
			else
				return (0);
		}
	}
	return (j);
}
