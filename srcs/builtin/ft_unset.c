/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:28:22 by mwane             #+#    #+#             */
/*   Updated: 2021/01/11 18:09:40 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/gnl/get_next_line.h"
#include "../../headers/minishell.h"

void 	ft_clean_elem(t_env	**env);

int     check_variable(char *str);


t_env	*search_for_var(char *data, t_env *env)
{
	t_env	*tmp;
	t_env	*next;
	t_env	*prev;
	
	prev = NULL;
	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(data, tmp->key) == 0)
		{
			next = tmp->next;
			ft_clean_elem(&tmp);
			if (!(prev))
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
	int i;
    
    i = 1;
    if (!(argv[1]))
       return (0);   
    while (argv[i])
    {
		if (check_variable(argv[i]) == -1)
			return (-1);
		shell->env = search_for_var(argv[i], shell->env);
		i++;
	}
	return (0);
}
