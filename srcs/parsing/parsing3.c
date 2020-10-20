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
char	**ft_split_custom(char const *s, char c);

char        *fusion(char **args);

char        *replace_line(t_env *env, char *line)
{
    int     i;
    int     flags;
    char    *result;
    char    **tmp;
    void    *save;


    tmp = split_$(line);
    i = 0;
    save = env;
    while (tmp[i])
    {
        env = save;
        flags = 0;
        if (tmp[i][0] == '$')
        {
            while (env)
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
                    tmp[i] = "7";
                    break;
                }
                if (tmp[i][1] == '?')
                {
                    flags = 1;
                    free(tmp[i]);
                    tmp[i] = "1";
                    break;
                }
                if (ft_strcmp(env->key, (tmp[i] + 1)) == 0)
                {
                    free(tmp[i]);
                    tmp[i] = env->value;
                    flags = 1;
                    break;
                }
                else 
                    env = env->next;
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
