/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 19:07:59 by mwane             #+#    #+#             */
/*   Updated: 2019/10/13 18:41:18 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*nstr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (!(nstr = malloc(size * nmemb)))
		return (NULL);
	ft_bzero(nstr, nmemb);
	return (nstr);
}
