/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:50:29 by davlasov          #+#    #+#             */
/*   Updated: 2019/12/12 17:48:46 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putstr_cut(char *s, int k, int *p)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && i < k)
	{
		ft_putchar(s[i], p);
		i++;
	}
}

int		ft_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_s(char *str, t_list *new, int *p)
{
	int		len;

	if (str == NULL)
	{
		str = malloc(7);
		str[6] = '\0';
		str = "(null)";
	}
	len = ft_len(str);
	len > new->precision && new->precision != -1 ? len = new->precision : 0;
	len < new->width ? new->zero = new->width - len : new->zero == 0;
	new->padding == 'l' ? ft_write_space(new->zero, p) : 0;
	ft_putstr_cut(str, len, p);
	new->padding == 'r' ? ft_write_space(new->zero, p) : 0;
}
