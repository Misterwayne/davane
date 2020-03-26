/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:35:50 by davlasov          #+#    #+#             */
/*   Updated: 2019/12/12 18:14:46 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_write(int *p, va_list ap, t_list *new)
{
	new->specifier == 'd' || new->specifier == 'i' ?
	ft_d(va_arg(ap, int), new, p) : 0;
	new->specifier == 'u' ? ft_d(va_arg(ap, unsigned int), new, p) : 0;
	new->specifier == 'x' ? ft_x(va_arg(ap, unsigned int), new, p) : 0;
	new->specifier == 'X' ? ft_x_up(va_arg(ap, unsigned int), new, p) : 0;
	new->specifier == 'p' ?
	ft_p((uintptr_t)(va_arg(ap, long long*)), new, p) : 0;
	new->specifier == 'c' ? ft_c(va_arg(ap, unsigned int), new, p) : 0;
	new->specifier == '%' ? ft_percent(new, p) : 0;
	new->specifier == 's' ? ft_s(va_arg(ap, char *), new, p) : 0;
}

void		ft_find_specifers(int *p, char *str, va_list ap, t_list *new)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			ft_fill_list(new);
			i++;
			ft_flags(&i, str, ap, new);
			ft_write(p, ap, new);
		}
		else
		{
			ft_putchar(str[i], p);
			i++;
		}
	}
}

int			ft_printf(char *str, ...)
{
	va_list		ap;
	t_list		new;
	int			p;

	p = 0;
	//new = ft_newlist();
	ft_fill_list(&new);
	va_start(ap, str);
	ft_find_specifers(&p, str, ap, &new);
	va_end(ap);
	//free(new);
	return (p);
}
