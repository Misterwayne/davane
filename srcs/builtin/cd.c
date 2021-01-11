/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:12:47 by truepath          #+#    #+#             */
/*   Updated: 2021/01/11 18:58:44 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	change_pwd(t_shell **shell)
{
	t_env *env;
	char *path;

	env = (*shell)->env;
	while (env)
		{
			if (ft_strcmp(env->key, "PWD") == 0)
			{
				free(env->value);
    			path = malloc(sizeof(char)* 1024);
    			getwd(path);
				env->value = path;
				return ;
			}
			env = env->next;
		}
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
