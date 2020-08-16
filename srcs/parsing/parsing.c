/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:27:13 by truepath          #+#    #+#             */
/*   Updated: 2020/08/16 14:37:06 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    load_cmd(t_cmd *cmd)
{
    cmd->cmd_lst[0] = "pwd";
    cmd->cmd_lst[1] = "cd";
    cmd->cmd_lst[2] = "export";
    cmd->cmd_lst[3] = "env";
    cmd->cmd_lst[4] = "unset";
    cmd->cmd_lst[5] = "echo";
    cmd->cmd_lst[6] = NULL;
}

int     check_commande(t_cmd *cmd, char *line)
{
    int i;

    i = 0;
    while (cmd->cmd_lst[i] != NULL)
    {
        if (ft_strcmp(cmd->cmd_lst[i], line) == 0)
            return (1);
        i++;
    }
    return (0);
}
