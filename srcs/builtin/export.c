/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 00:12:02 by truepath          #+#    #+#             */
/*   Updated: 2020/09/23 13:10:11 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    display_var(char **argv, t_env *env);
t_env   *ft_create_elem(char *data);

int    find_variable(t_env *env, t_env *new)
{
    while(env)
    {
        if (ft_strcmp(env->key, new->key) == 0)
        {
            free(env->value);
            env->value = new->value;
            return (-1);
        }
        env = env->next;
    }
    return (0);
}

void    add_variable(t_env *env, char *data)
{
   	t_env	*tmp;
	
	if (!(env))
	{
		env = ft_create_elem(data);
		return ;
	}
	else
	{
		tmp = ft_create_elem(data);
        if (find_variable(env, tmp) == -1)
            return ;
		while(env->next)
            env = env->next;
        env->next = tmp;
        return ;
	}
}

int     export(char **argv, t_shell *shell)
{
    if (!(argv[1]))
        display_var(argv, shell->env);
    else
        add_variable(shell->env, (shell->line + 7));
    return (0);
}
