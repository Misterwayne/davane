/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 16:45:00 by mwane             #+#    #+#             */
/*   Updated: 2019/10/18 13:35:34 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return ((unsigned char)*s1 - (unsigned char)*s2);
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	j += (unsigned char)s1[i] - (unsigned char)s2[i];
	return (j);
}
