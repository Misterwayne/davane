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

void    load_cmd(t_cmd *cmd)
{
    cmd->cmd_lst[0] = "pwd";
    cmd->cmd_lst[1] = "cd";
    cmd->cmd_lst[2] = "export";
    cmd->cmd_lst[3] = "env";
    cmd->cmd_lst[4] = "unset";
    cmd->cmd_lst[5] = "echo";
    cmd->cmd_lst[6] = NULL;
    cmd->builtin_array[0] = &pwd;
    cmd->builtin_array[1] = &cd;
    cmd->builtin_array[2] = &export;
    cmd->builtin_array[3] = &env;
    cmd->builtin_array[4] = &unset;
    cmd->builtin_array[5] = &echo;
    cmd->builtin_array[6] = &ft_exit;
    cmd->builtin_array[7] = NULL;
}

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


void	change_env_vars(char **args, t_env *env, int i)
{
    while (env)
    {
        if (ft_strcmp(env->key, (args[i] + 1)) == 0)
        {
            free(args[i]);
            args[i] = env->value; 
            return ;
        }
        env = env->next;
    }
    args[i] = "";
}