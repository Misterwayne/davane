/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 00:12:02 by truepath          #+#    #+#             */
/*   Updated: 2021/01/11 15:02:04 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_env   *ft_create_elem(char *data);
char	*ft_name(char *s);

void	export_without_arguments(t_env *env)
{
	while(env)
	{
		ft_printf("declare -x ");
        ft_printf("%s", env->key);
		ft_printf("=");
		ft_printf("%s\n", env->value);
		env = env->next;
	}
}

int    find_variable(t_env **env, t_env *new)
{   
    t_env *tmp;
    t_env *beginin_list;

    tmp = *env;
    //(*env)->next->key = "CHECK";

    // tmp = *env;
    // beginin_list = tmp;
    while(tmp)
    {
         tmp->value = "100";
         return  0; 
    //    if (ft_strcmp(tmp->key, new->key) == 0)
    //    {
    //        tmp->value = "100";
    //        ft_printf("OK!");
    //        return 0; 
    //    }
        tmp = tmp->next;
    }
    //*env = *env->next;
    //*env = *new;
    //ft_printf("%s", (*env)->next->key);
    return (0);
}

void    add_variable(t_shell **shell, char *data)
{
   	t_env	*new;
    t_env   *env;
	
    new = ft_create_elem(data);
    env = (*shell)->env;
    if (find_variable(&env, new) == 1)
            return ;
    while (env)
        {
            ft_printf("%s", env->value);
            env = env->next;
        }
    // while (env->next)
    //     env = env->next;
    // env->next = new;
    ft_printf("OK2\n");
}

int     export(char **argv, t_shell *shell)
{
    add_variable(&shell, argv[1]);
    ft_printf("old: %s", shell->env->value);
    // if (argv[1])
    //     add_variable(shell->env, argv[1]);
    // else
    //    export_without_arguments(shell->env);
    return (0);
}
