/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:27:13 by truepath          #+#    #+#             */
/*   Updated: 2020/10/17 13:51:32 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int     as_dollar_inside(char *line);

char        *fusion(char **args);

char        *replace_line(t_shell *shell, char *line)
{
    int     i;
    int     flags;
    char    *result;
    char    **tmp;
    void    *save;

    if (as_dollar_inside(line))
    {
        tmp = split_dollar(line);
        i = 0;
        save = shell->env;
        while (tmp[i])
        {
            shell->env = save;
            flags = 0;
            if (tmp[i][0] == '$')
            {
                while (shell->env)
                {
                    if (tmp[i][1] == '\0')
                    {
                        flags = 1;
                        free(tmp[i]);
                        tmp[i] = "$";
                        break;
                    }
                    if (tmp[i][1] == '$')
                    {
                        flags = 1;
                        free(tmp[i]);
                        tmp[i] = ft_itoa(shell->last_pid);
                        break;
                    }
                    if (tmp[i][1] == '?')
                    {
                        flags = 1;
                        free(tmp[i]);
                        tmp[i] = ft_itoa(shell->last_return);
                        break;
                    }
                    if (ft_strcmp(shell->env->key, (tmp[i] + 1)) == 0)
                    {
                        free(tmp[i]);
                        tmp[i] = shell->env->value;
                        flags = 1;
                        break;
                    }
                    else 
                        shell->env = shell->env->next;
                }
                if (flags == 0)
                {
                    free(tmp[i]);
                    tmp[i] = ft_strdup("");
                }
            }
            i++;
        }
        i = 0;
        result = fusion(tmp);
        return (result);
    }
    return (line);
}

char        *fusion(char **args)
{
    int     i;
    char    *result;

    result = "";
    i = 0;
    while (args[i])
    {
        result = ft_strjoin(result, args[i]);
        i++;
    }
    return (result);
}

int     as_dollar_inside(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] == '$')
            return (1);
        i++;
    }
    return (0);
}
