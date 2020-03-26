/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:16:05 by davlasov          #+#    #+#             */
/*   Updated: 2020/01/10 17:10:51 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int				ft_read(int fd, char **line, char *buf)
{
	int		red;
	int		i;

	i = -1;
	red = 1;
	while (i == -1 && red != 0)
	{
		ft_fill(BUFFER_SIZE, &buf[0]);
		if ((red = read(fd, &buf[0], BUFFER_SIZE)) == -1)
			return (-1);
		if (!(*line = ft_strjoin(*line, &buf[0])))
			return (-1);
		i = ft_find_n(&buf[0]);
	}
	if (i != -1)
		ft_memmove(&buf[0], &(buf[i + 1]), BUFFER_SIZE + 1);
	if (red == 0)
		return (0);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	int			red;
	int			i;
	static char	buf[BUFFER_SIZE + 1];

	i = -1;
	red = 1;
	if (BUFFER_SIZE < 1 || fd < 0 || line == 0)
		return (-1);
	*line = NULL;
	if (buf[0])
	{
		if (!(*line = ft_strjoin(*line, &buf[0])))
			return (-1);
		i = ft_find_n(&buf[0]);
		if (i != -1)
			ft_memmove(&buf[0], &(buf[i + 1]), BUFFER_SIZE + 1);
	}
	if (i == -1)
		return (ft_read(fd, line, &buf[0]));
	return (1);
}
