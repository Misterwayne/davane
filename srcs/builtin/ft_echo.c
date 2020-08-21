/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:18:54 by truepath          #+#    #+#             */
/*   Updated: 2020/08/21 16:01:45 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	print_arguments(char **argv, t_env *env)
{
	int i;

	i = 1;
	while (argv[i] != NULL)
	{
		ft_printf("%s ", argv[i]);
		i++;
	}
}

void open_write(char **argv, t_env *env)
{
	print_arguments(argv, env);
}

int		echo(char **argv, t_shell *shell)
{
	open_write(argv, shell->env);
	ft_printf("\n");
	return (0);
}
