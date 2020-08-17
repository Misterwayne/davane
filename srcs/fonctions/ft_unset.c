/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:28:22 by mwane             #+#    #+#             */
/*   Updated: 2020/08/17 14:37:46 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/gnl/get_next_line.h"
#include "../../headers/minishell.h"


void	replace(char **argv, int fd, int n, char *line)
{
	int fd_new;
	int i;
	int red;
	int red_new;
	char *line_new;

	i = 0;
	red = 1;
	fd_new = open("var.txt", O_RDWR);
	while (i < n)
	{
		red_new = get_next_line(fd_new, &line);
		i++;
	}
	write(fd_new, line, ft_strlen(line));
	while (red == 1)
	{
		red = get_next_line(fd, &line);
		red_new = get_next_line(fd_new, &line_new);
		write(fd_new, line, ft_strlen(line));
	}
	//write(fd_new, "\0", 1);
	close(fd);
	close(fd_new);

}

void	search_for_var(char **argv, int fd)
{
	char *line;
	int red;
	char **data;
	int i;

	i = 0;
	red = 1;
	while(red == 1)
	{
		red = get_next_line(fd, &line);
		stpcpy(data[i], line);
		printf("%s", data[i]);
		if (strstr(line, argv[1]))
			{
				//replace(argv, fd, i, line);
				return;
			}
		free(line);
		i++;
	}
	close(fd);
}


void	open_close(char **argv)
{
	int fd;

	fd = open("var.txt", O_RDWR);
	search_for_var(argv, fd);
}


int		unset(char **argv)
{
	open_close(argv);
	return (0);
}