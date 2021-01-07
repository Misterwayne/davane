/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:27:13 by truepath          #+#    #+#             */
/*   Updated: 2020/10/17 13:47:28 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int     check_commande(t_cmd *cmd, char *line)
{
    int i;

    i = 0;
    if (line == NULL)
        return (-3);
    while (cmd->cmd_lst[i] != NULL)
    {
        if (ft_strcmp(cmd->cmd_lst[i], line) == 0)
            return (i);
        i++;
    }
    return (-2);
}

int     get_dollar(char *s, char *res, int i)
{
    if (s[i + 1] == '$')
	{
	    while (i < 2)
	    {
		    res[i] = s[i];
		    i++;
	    }
	    res[i] = '\0';
	    return (i);
	}
	while (s[i] != ' ' && s[i])
	{
		res[i] = s[i];
		i++;
		if (s[i] == '$' || s[i] == '=')
			break;
	}
	res[i] = '\0';
	return (i);
}