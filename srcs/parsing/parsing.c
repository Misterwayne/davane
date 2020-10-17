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
    // initialize the array function and the list of commandes
    cmd->cmd_lst[0] = "pwd";
    cmd->cmd_lst[1] = "cd";
    cmd->cmd_lst[2] = "export";
    cmd->cmd_lst[3] = "env";
    cmd->cmd_lst[4] = "unset";
    cmd->cmd_lst[5] = "echo";
    cmd->cmd_lst[6] = NULL;
    // initialize the array of pointer to function
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

    // parse the commande list to find a match then return the index
    i = 0;
    if (line == NULL)
        return (ERROR);
    while (cmd->cmd_lst[i] != NULL)
    {
        if (ft_strcmp(cmd->cmd_lst[i], line) == 0)
            return (i);
        i++;
    }
    return (ERROR);
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

void    check_v(t_shell *shell, char **args)// this function will check if $str is a key to a value if yes returns it or return NULL
{
    int i; 
    
    i = 0;
    while (args[i])
    {
        if (args[i][0] == '$')
        {
            if (args[i][1] == '?')
            {
                    free(args[i]);
                    args[i] = ft_itoa(shell->last_return);
                    return ; 
            }
            if (args[i][1] == '$')
            {
                    free(args[i]);
                    args[i] = ft_itoa(shell->last_pid);
                    return ;
            }
            change_env_vars(args, shell->env, i);
        }
        i++;
    }
}
