/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:37:55 by davlasov          #+#    #+#             */
/*   Updated: 2019/12/12 12:39:19 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int			ft_find_number(int *i, char *str)
{
	int		w;

	w = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		w = w * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (w);
}

void		ft_padding(int *i, char *str, t_list *new)
{
	if (str[*i] == '-')
	{
		new->padding = 'r';
		(*i)++;
		while (str[*i] == '-')
			(*i)++;
	}
	if (str[*i] == '0')
	{
		if (str[*i + 1] == '-')
		{
			new->padding = 'r';
			(*i)++;
		}
		else
			new->space_zero = '0';
		(*i)++;
	}
}

void		ft_width(int *i, char *str, va_list ap, t_list *new)
{
	if (str[*i] >= '0' && str[*i] <= '9')
		new->width = ft_find_number(i, str);
	if (str[*i] == '*')
	{
		new->width = va_arg(ap, long);
		if (new->width < 0)
		{
			new->width = new->width * (-1);
			new->padding = 'r';
		}
		(*i)++;
	}
}

void		ft_specifier(int *i, char *str, va_list ap, t_list *new)
{
	if (str[*i] == '.')
	{
		new->precision = 0;
		(*i)++;
		if (str[*i] >= '0' && str[*i] <= '9')
			new->precision = ft_find_number(i, str);
		if (str[*i] == '*')
		{
			new->precision = va_arg(ap, int);
			new->precision < 0 ? new->precision = -1 : 0;
			(*i)++;
		}
	}
}

void		ft_flags(int *i, char *str, va_list ap, t_list *new)
{
	ft_padding(i, str, new);
	ft_width(i, str, ap, new);
	ft_specifier(i, str, ap, new);
	new->specifier = str[*i];
	(*i)++;
}
