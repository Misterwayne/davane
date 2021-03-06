/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:25:41 by mwane             #+#    #+#             */
/*   Updated: 2020/08/19 18:04:21 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	ft_exit_error(int error, char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(error);
}


int		ft_exit(char **argv, t_shell *shell)
{
	(void)shell;
	(void)argv;
	exit(0);
}
