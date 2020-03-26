/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:45:05 by davlasov          #+#    #+#             */
/*   Updated: 2019/12/12 11:46:16 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_c(char c, t_list *new, int *p)
{
	new->space = new->width - 1;
	new->padding == 'l' ? ft_write_space(new->space, p) : 0;
	ft_putchar(c, p);
	new->padding == 'r' ? ft_write_space(new->space, p) : 0;
}

void	ft_percent(t_list *new, int *p)
{
	new->padding == 'r' ? new->space_zero = ' ' : 0;
	new->space_zero == '0' ? new->zero = new->width - 1 : 0;
	new->space = new->width - 1 - new->zero;
	new->padding == 'l' ? ft_write_space(new->space, p) : 0;
	ft_write_zero(new->zero, p);
	ft_putchar('%', p);
	new->padding == 'r' ? ft_write_space(new->space, p) : 0;
}
