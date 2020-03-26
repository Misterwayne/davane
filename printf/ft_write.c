/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:51:11 by davlasov          #+#    #+#             */
/*   Updated: 2019/12/12 11:55:46 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_write_zero(int k, int *p)
{
	while (k > 0)
	{
		write(1, "0", 1);
		(*p)++;
		k--;
	}
}

void	ft_write_space(int k, int *p)
{
	while (k > 0)
	{
		write(1, " ", 1);
		(*p)++;
		k--;
	}
}

void	ft_putchar(unsigned char c, int *p)
{
	write(1, &c, 1);
	(*p)++;
}

void	ft_putnbr(long n, int *p)
{
	int		i;
	long	nb;

	i = 1;
	nb = n;
	while (nb / 10 > 0)
	{
		i = i * 10;
		nb = nb / 10;
	}
	nb = n;
	while (i > 0)
	{
		ft_putchar(nb / i + '0', p);
		nb = nb % i;
		i = i / 10;
	}
}
