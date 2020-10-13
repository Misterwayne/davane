/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:27:13 by truepath          #+#    #+#             */
/*   Updated: 2020/10/13 21:07:52 by truepath         ###   ########.fr       */
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
    cmd->cmd_lst[6] = "exit";
    cmd->cmd_lst[7] = NULL;
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

int 	change_env_vars(char **args, t_env *env, int i, int y)
{
    char *new_line;
    char *tmp;
    while (env)
    {
        if (ft_strncmp(env->key, (args[i] + y + 1), ft_strlen(env->key)) == 0)
        {
            if (y > 0)
            {
                tmp = ft_strndup(args[i], y);
                new_line = ft_strjoin(tmp, env->value);
                // free(args[i]);
                // free(tmp);
                args[i] = new_line;
                // free(new_line);
                return (1);
            }
            else
            {
                // free(args[i]);
                args[i] = env->value;
                return (1);
            }
        }
        env = env->next;
    }
    // free(args[i]);
    args[i] = "";
    return (0);
}

void     check_v(t_shell *shell, char **args)// this function will check if $str is a key to a value if yes returns it or return NULL
{
    int i;
    int y;
    
    i = 0;
    y = 0;
    while (args[i])
    {
        while (args[i][y])
        {
            if (args[i][y] == '$')
            {
                if (args[i][y + 1] == '?')
                {
                    // free(args[i]);
                    args[i] = ft_itoa(shell->last_return);
                    return ; 
                }
                if (args[i][y + 1] == '$')
                {
                    // free(args[i]);
                    args[i] = ft_itoa(shell->last_pid);
                    return ;
                }
                change_env_vars(args, shell->env, i, y);
            }
            y++;
        }
        i++;
        y = 0;
    }
    return ;
}
