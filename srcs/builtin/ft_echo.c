/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:18:54 by truepath          #+#    #+#             */
/*   Updated: 2020/08/18 17:58:05 by mwane            ###   ########.fr       */
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

void open_write(char **argv)
{
	print_arguments(argv);
}

int		echo(char **argv)
{

	printf("\n");
	open_write(argv);
	printf("\n");
	return (0);
}