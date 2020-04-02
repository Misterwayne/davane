/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:03:22 by davlasov          #+#    #+#             */
/*   Updated: 2019/12/12 18:13:48 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_list
{
	char	padding;
	char	space_zero;
	int		width;
	int		precision;
	char	specifier;
	int		len;
	int		minus;
	int		space;
	int		zero;

}				t_list;

t_list			ft_newlist(void);
void			ft_fill_list(t_list *new);
int				ft_printf(char *str, ...);
void			ft_flags(int *i, char *str, va_list ap, t_list *new);
void			ft_write_zero(int k, int *p);
void			ft_write_space(int k, int *p);
void			ft_putchar(unsigned char c, int *p);
void			ft_putnbr(long n, int *p);
void			ft_d(long n, t_list *new, int *p);
void			ft_c(char c, t_list *new, int *p);
void			ft_s(char *str, t_list *new, int *p);
void			ft_x(unsigned long long n, t_list *new, int *p);
void			ft_x_up(unsigned long long n, t_list *new, int *p);
void			ft_p(unsigned long long n, t_list *new, int *p);
void			ft_percent(t_list *new, int *p);

#endif
