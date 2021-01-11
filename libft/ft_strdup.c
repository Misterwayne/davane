/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:45:06 by mwane             #+#    #+#             */
/*   Updated: 2021/01/11 16:20:08 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*nstr;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != 0)
		i++;
	if (!(nstr = malloc((sizeof(char) * (i + 1)))))
		return (NULL);
	i = -1;
	while (str[++i])
		nstr[i] = str[i];
	nstr[i] = '\0';
	return (nstr);
}
