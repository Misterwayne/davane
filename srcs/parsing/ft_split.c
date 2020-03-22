/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 11:59:20 by davlasov          #+#    #+#             */
/*   Updated: 2019/11/12 15:33:06 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen_split(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

int		ft_strcount(char *s, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n = n + 1;
		i++;
	}
	return (n);
}

char	*ft_full(char const *s, int len)
{
	char	*tmp;
	int		j;
	int		k;

	j = 0;
	k = 0;
	if (!(tmp = malloc(len + 1)))
		return (0);
	while (j < len)
		tmp[j++] = s[k++];
	tmp[j] = '\0';
	return (tmp);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		k;
	int		len;
	int		len_arr;

	i = 0;
	k = 0;
	len_arr = ft_strcount((char *)s, c);
	if (!(arr = malloc(sizeof(char *) * (len_arr + 1))))
		return (0);
	while (i < len_arr)
	{
		while (((char *)s)[k] == c)
			k++;
		len = ft_strlen_split(&(((char *)s)[k]), c);
		if (!(arr[i] = malloc(len + 1)))
			return (0);
		arr[i] = ft_full(&(((char *)s)[k]), len);
		while ((((char *)s)[k]) != c && (((char *)s)[k]) != '\0')
			k++;
		i++;
	}
	arr[i] = 0;
	return (arr);
}
