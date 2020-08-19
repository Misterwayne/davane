/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:29:07 by mwane             #+#    #+#             */
/*   Updated: 2020/08/19 19:27:02 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"
#include "../parsing/gnl/get_next_line.h"

void	display_var(char **argv, t_env *env)
{
	while(env)
	{
		ft_printf("%s", env->key);
		ft_printf("=");
		ft_printf("%s\n", env->value);
		if (env->next)
			env = env->next;
		else
			return ;
	}
}

int 	env(char **argv, t_shell *shell)
{
	display_var(argv, shell->env);
	return (0);
}
