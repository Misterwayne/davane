/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 00:12:02 by truepath          #+#    #+#             */
/*   Updated: 2020/08/20 16:30:22 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    display_var(char **argv, t_env *env);
t_env   *ft_create_elem(char *data);

void    add_variable(t_env *list, char *data)
{
   	t_env	*tmp;
	
	if (!(list))
	{
		list = ft_create_elem(data);
		return ;
	}
	else
	{
		tmp = ft_create_elem(data);
		while(list->next)
			{
                if (list->key == tmp->key)
                    {
                        list->value = tmp->value;
                        return ;
                    }
                list = list->next;
            }
		list->next = tmp;
        return ;
	}
}

int     export(char **argv, t_shell *shell)
{
    if (!(argv[1]))
        display_var(argv, shell->env);
    else
        add_variable(shell->env, argv[1]);
    return (0);
}
