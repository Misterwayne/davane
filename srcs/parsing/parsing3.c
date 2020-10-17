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


    tmp = ft_split_custom(line, '$');
    i = 0;
    save = env;
    while (tmp[i])
    {
        // ft_printf("pre change : %s\n",tmp[i]);
        env = save;
        flags = 0;
        if (tmp[i][0] == '$')
        {
            while (env)
            {
                if (ft_strcmp(env->key, (tmp[i] + 1)) == 0)
                {
                    // ft_printf("%s = %s\n",env->key, tmp[i]);
                    tmp[i] = env->value;
                    flags = 1;
                    break;
                }
                else 
                    env = env->next;
            }
            if (flags == 0)
                tmp[i] = ft_strdup(" ");
        }
        // ft_printf("%s with flags %d\n",tmp[i],flags);
        i++;
    }
    i = 0;
    result = fusion(tmp);
    // while(tmp[i])
    //     ft_printf("post change : %s\n",tmp[i++]);
    // ft_printf("result : %s\n", result);
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
        // ft_printf("%s\n",result);
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
