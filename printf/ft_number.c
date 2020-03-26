/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:48:36 by davlasov          #+#    #+#             */
/*   Updated: 2019/12/12 11:50:00 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_length(long long n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void			ft_d(long n, t_list *new, int *p)
{
	!(new->precision == 0 && n == 0) ? new->len = ft_length(n) : 0;
	new->padding == 'r' || new->precision != -1 ? new->space_zero = ' ' : 0;
	new->space_zero == '0' ? new->zero = new->width - new->len : 0;
	if (n < 0)
	{
		new->minus = 1;
		n = n * (-1);
		(new->precision)++;
	}
	new->len < new->precision ? new->zero = new->precision - new->len : 0;
	new->space = new->width - new->len - new->zero;
	new->padding == 'l' ? ft_write_space(new->space, p) : 0;
	new->minus == 1 ? ft_putchar('-', p) : 0;
	ft_write_zero(new->zero, p);
	!(new->precision == 0 && n == 0) ? ft_putnbr(n, p) : 0;
	new->padding == 'r' ? ft_write_space(new->space, p) : 0;
}
