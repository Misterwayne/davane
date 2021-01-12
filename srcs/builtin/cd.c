/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:12:47 by truepath          #+#    #+#             */
/*   Updated: 2021/01/12 12:03:35 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_env	*create_old_pwd(char *value)
{
	t_env *elem;

	elem = malloc(sizeof(t_env));
	elem->key = malloc(sizeof("OLDPWD"));
	elem->key = "OLDPWD";
	elem->value = value;
	elem->next = NULL;
	return (elem);
}

void	change_old_pwd(t_shell **shell, char *oldpwd)
{
	t_env *env;
	char *path;

	env = (*shell)->env;
	while (env)
		{
			if (ft_strcmp(env->key, "OLDPWD") == 0)
			{
				free(env->value);
				env->value = oldpwd;
				return ;
			}
			if (!(env->next))
				env->next = create_old_pwd(oldpwd);
			env = env->next;
		}	
}

void	change_pwd(t_shell **shell)
{
	t_env *env;
	char *oldpwd;
	char *path;

	env = (*shell)->env;
	while (env)
		{
			if (ft_strcmp(env->key, "PWD") == 0)
			{
				oldpwd = env->value;
    			path = malloc(sizeof(char)* 1024);
    			getwd(path);
				env->value = path;
				break ;
			}
			env = env->next;
		}
	change_old_pwd(shell, oldpwd);
}

int     cd(char **argv, t_shell *shell)
{   
	char  *path;
	t_env *env;

	env = shell->env;
	if (!(argv[1]))
		{
			while (env)
			{
				if (ft_strcmp(env->key, "HOME") == 0)
				{
					chdir(env->value);
					change_pwd(&shell);
					return (0);
				}
				env = env->next;
			}
			return (-1);
		}
	path = argv[1];
	if (chdir(path) == -1)
	{
		write(1, "cd: no such file or directory: ", 31);
		write(1, path, strlen(path));
		write(1, "\n", 1);
		return (-1);
	}
	change_pwd(&shell);
	return (0);
}
