/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:28:22 by mwane             #+#    #+#             */
/*   Updated: 2020/08/20 19:09:21 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing/gnl/get_next_line.h"
#include "../../headers/minishell.h"

void	search_for_var(char **argv, t_env *env)
{
	t_env	*tmp;
	t_env	*next;
	t_env	*prev;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(argv[1], tmp->key) == 0)
		{
			ft_printf("CHECK");
			// prev = tmp->prev;
			// next = tmp->next;
			// free(tmp->key);
			// free(tmp->next);
			//free(tmp);
			//prev = next;
			// prev->next = next;
			// next->prev = prev;
		}
		tmp = tmp->next;
	}
}

int		unset(char **argv, t_shell *shell)
{
	//open_close(argv);
	search_for_var(argv, shell->env);
	return (0);
}
