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

char	*call_set(void);

void	put_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\"')
			write(1, &str[i], 1);
		i++;
	}
}

void	print_arguments(char **argv, t_shell *shell)
{
	int		i;
	t_env	*env;
	char	*var;

	env = shell->env;
	i = 1;
	put_str(argv[i++]);
	while (argv[i] != NULL)
	{
		var = call_set();
		ft_printf(" ");
		put_str(argv[i]);
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
