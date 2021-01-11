/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:29:07 by mwane             #+#    #+#             */
/*   Updated: 2021/01/11 12:11:35 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../parsing/gnl/get_next_line.h"

void	display_var(t_env *env)
{
	while(env)
	{
		ft_printf("%s", env->key);
		ft_printf("=");
		ft_printf("%s\n", env->value);
		env = env->next;
	}
	ft_printf("!\n");
}

int 	env(char **argv, t_shell *shell)
{
	if (argv[1])
		{
			ft_printf("too many arguments");
			return (-1);
		}
	display_var(shell->env);
	return (0);
}
