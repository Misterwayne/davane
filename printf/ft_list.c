/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:46:47 by davlasov          #+#    #+#             */
/*   Updated: 2019/12/12 18:14:41 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_fill_list(t_list *new)
{
	new->padding = 'l';
	new->space_zero = ' ';
	new->width = 0;
	new->precision = -1;
	new->specifier = '0';
	new->minus = 0;
	new->space = 0;
	new->zero = 0;
	new->len = 0;
}