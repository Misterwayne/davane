/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:18:54 by truepath          #+#    #+#             */
/*   Updated: 2020/08/17 15:25:28 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	print_arguments(char **argv)
{
	int i;

	i = 1;

	while (argv[i] != NULL)
	{
		ft_printf("%s", argv[i]);
		i++;
	}
}

void	add_text(char **argv, int fd)
{
	char *buf;
	int ret;

	ret = 1;
	ft_printf("add_text");
	while (ret != 0)
		ret = read(fd, buf, 1);
	write(fd, argv[1], ft_strlen(argv[1]));
	write(fd, "\n", 1);
}

void	rewrite_text(char **argv, int fd)
{
	char *buf;

	ft_printf("rewrite_text");
	write(fd, argv[1], ft_strlen(argv[1]));
	write(fd, "\n", 1);
}

void open_write(char **argv)
{
	int fd;
	char *buf;

	fd = open("text.txt", O_RDWR);

 
	print_arguments(argv);
	close(fd);
}

int		echo(char **argv)
{

	printf("\n");
	open_write(argv);
	printf("\n");
	return (0);
}