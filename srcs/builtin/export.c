/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 00:12:02 by truepath          #+#    #+#             */
/*   Updated: 2021/01/11 18:08:47 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_env   *ft_create_elem(char *data);
char	*ft_name(char *s);
void 	ft_clean_elem(t_env	**env);

int     check_variable(char *str)
{
    int i;
    i = 0;
    if (!(str))
        return (0);
    while(str[i] != '\0')
    {
        if((str[i]) < 48 || (str[i] > 57 && str[i] < 65)|| str[i] > 122 || (str[i] > 90 && str[i] < 97))
            if (str[i] != '\'' && str[i] != '\"')
            {
                ft_printf("minishell:  export: `%c' not a valid identifier\n", str[i]);
                return (-1);
            }
        i++;
    }
    return (0);
}

int	export_without_arguments(t_env *env)
{
	while(env)
	{
		ft_printf("declare -x ");
        ft_printf("%s", env->key);
		ft_printf("=");
		ft_printf("%s\n", env->value);
		env = env->next;
	}
    return (0);
}

int    find_variable(t_env **env, t_env *new)
{   
    t_env *tmp;

    tmp = *env;
    while(tmp)
    {
       if (ft_strcmp(tmp->key, new->key) == 0)
       {
           free(tmp->value);
           tmp->value = new->value;
           free(new->key);
           free(new);
           return (1); 
       }
        tmp = tmp->next;
    }
    return (0);
}

int   add_variable(t_shell *shell, char *data)
{
   	t_env	*new;
    t_env   *env;
	
    new = ft_create_elem(data);
    if (check_variable(new->key) == -1)
    {
        ft_clean_elem(&new);
        return (-1);
    }
    if (!(new->value))
    {
        ft_clean_elem(&new);
        return (0);
    } 
    env = shell->env;
    if (find_variable(&env, new) == 1)
        return (0);
    while (env->next)
        env = env->next;
    env->next = new;
    return (0);
}

int     export(char **argv, t_shell *shell)
{
    int i;
    
    i = 1;
    if (!(argv[1]))
        return (export_without_arguments(shell->env));   
    while (argv[i])
    {
        if (add_variable(shell, argv[i]) == -1)
            return (-1);
        i++;
    }
    return (0);
}
