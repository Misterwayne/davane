/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:54:17 by davlasov          #+#    #+#             */
/*   Updated: 2019/12/12 18:05:10 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static long		ft_length(long long n)
{
	long		i;

	i = 1;
	while (n > 15)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void		ft_convert_to_hex(unsigned long long n, int *p)
{
	char				*base;
	unsigned long long	nb;
	unsigned long long	i;

	base = "0123456789abcdef";
	nb = n;
	i = 1;
	while (nb > 15)
	{
		i = i * 16;
		nb = nb / 16;
	}
	nb = n;
	while (i > 0)
	{
		ft_putchar(base[nb / i], p);
		nb = nb % i;
		i = i / 16;
	}
}

void			ft_x(unsigned long long n, t_list *new, int *p)
{
	!(new->precision == 0 && n == 0) ? new->len = ft_length(n) : 0;
	new->padding == 'r' ? new->space_zero = ' ' : 0;
	(new->space_zero == '0' && new->precision == -1) ?
	new->zero = new->width - new->len : 0;
	new->len < new->precision ? new->zero = new->precision - new->len : 0;
	new->space = new->width - new->len - new->zero;
	new->padding == 'l' ? ft_write_space(new->space, p) : 0;
	new->minus == 1 ? ft_putchar('-', p) : 0;
	ft_write_zero(new->zero, p);
	!(new->precision == 0 && n == 0) ? ft_convert_to_hex(n, p) : 0;
	new->padding == 'r' ? ft_write_space(new->space, p) : 0;
}

void			ft_p(unsigned long long n, t_list *new, int *p)
{
	!(new->precision == 0 && n == 0) ? new->len = ft_length(n) + 2 : 0;
	new->padding == 'r' ? new->space_zero = ' ' : 0;
	(new->space_zero == '0' && new->precision == -1) ?
	new->zero = new->width - new->len : 0;
	new->len < new->precision ? new->zero = new->precision - new->len : 0;
	new->space = new->width - new->len - new->zero;
	new->padding == 'l' ? ft_write_space(new->space, p) : 0;
	new->minus == 1 ? ft_putchar('-', p) : 0;
	write(1, "0x", 2);
	(*p) = (*p) + 2;
	ft_write_zero(new->zero, p);
	ft_convert_to_hex(n, p);
	new->padding == 'r' ? ft_write_space(new->space, p) : 0;
}
