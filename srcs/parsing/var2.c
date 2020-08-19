/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 17:27:49 by mwane             #+#    #+#             */
/*   Updated: 2020/08/19 17:28:13 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int     is_in_list(t_var *var, char *line)
{
    t_var *l;
    int i;

    i = 0;
    l = var;
    while (line[i] != '=')
        i++;
    while (var != NULL)
    {
        if (ft_strncmp(var->key, line, i) == 0)
        {
            var = l;
            return (1);
        }
        var = var->prev;
    }
    return (0);
}

void    replace_var(t_var *var, char* line)
{
    int i;
    int j;
    char *new_value;

    i = 0;
    j = 0;
    new_value = malloc(sizeof(char) * ft_strlen(line));
    while(line[i] != '=')
        i++;
    i++;
    while (line[i])
        new_value[j++] = line[i++];
    free(var->value);
    var->value = new_value;
}