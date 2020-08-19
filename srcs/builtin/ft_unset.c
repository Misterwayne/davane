/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:28:22 by mwane             #+#    #+#             */
/*   Updated: 2020/08/19 18:04:31 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/gnl/get_next_line.h"
#include "../../headers/minishell.h"


void	replace(char **argv, int fd, int n, char *line)
{

}

void	search_for_var(char **argv, int fd)
{

}


void	open_close(char **argv)
{
	int fd;

	fd = open("var.txt", O_RDWR);
	search_for_var(argv, fd);
}


int		unset(char **argv, t_shell *shell)
{
	open_close(argv);
	return (0);
}