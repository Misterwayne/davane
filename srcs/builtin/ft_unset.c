/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:28:22 by mwane             #+#    #+#             */
/*   Updated: 2020/10/13 21:10:14 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/gnl/get_next_line.h"
#include "../../headers/minishell.h"

t_env	*search_for_var(char **argv, t_env *env)
{
	t_env	*tmp;
	t_env	*next;
	t_env	*prev;

	prev = 0;
	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(argv[1], tmp->key) == 0)
		{
			next = tmp->next;
			// free(tmp->key);
			// free(tmp->value);
			// free(tmp);
			if (prev == 0)
				env = next;
			else
				prev->next = next;
			return (env);
		}
		prev = tmp;
		tmp = tmp->next;
	}
	return (env);
}

int		unset(char **argv, t_shell *shell)
{
	shell->env = search_for_var(argv, shell->env);
	return (0);
}
