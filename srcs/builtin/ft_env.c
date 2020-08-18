/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:29:07 by mwane             #+#    #+#             */
/*   Updated: 2020/08/17 14:14:33 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../parsing/gnl/get_next_line.h"

void	display_var(char **argv)
{
	int fd;
	int red;
	char *line;

	fd = open("var.txt", O_RDONLY);
	red = 1;
	while(red == 1)
	{
		red = get_next_line(fd, &line);
		printf("%s\n", line);
		//free(line);
	}
	close(fd);
}

int 	env(char **argv)
{
	display_var(argv);
	return (0);
}
