/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:18:54 by truepath          #+#    #+#             */
/*   Updated: 2020/09/30 10:00:21 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	*call_set(void);

void	print_arguments(char **argv, t_shell *shell)
{
	int		i;
	t_env	*env;
	char	*var;

	env = shell->env;
	i = 1;
	while (argv[i] != NULL)
	{
		var = call_set();
		ft_printf("%s ", argv[i]);
		i++;
	}
	ft_printf("\n");
	exit(0);
}

int		echo(char **argv, t_shell *shell)
{
	print_arguments(argv, shell);
	ft_printf("\n");
	return (0);
}
