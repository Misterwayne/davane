/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:15:34 by mwane             #+#    #+#             */
/*   Updated: 2020/08/19 17:36:59 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

t_var        *new_node(char *line)
{
    t_var *new_node;
    char  *value;
    char  *key;
    int   i;
    int   j;

    i = 0;
    j = 0;
    new_node = (t_var *)malloc(sizeof(t_var));
    key = malloc(sizeof(char) * ft_strlen(line));
    value = malloc(sizeof(char) * ft_strlen(line));
    while (*line != '=')
        key[i++] = *line++;
    new_node->key = key;
    line++;
    while (*line != '\0')
        value[j++] = *line++;
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return (new_node);
}

t_var        *new_var(t_var *var, char *line)
{
    t_var *new_n;

    if (is_in_list(var, line))
    {
        replace_var(var, line);
        return (var);
    }
    else
    {
        new_n = new_node(line);
        var->next = new_n;
        new_n->prev = var;
        new_n->first = new_n;
        return (new_n);
    }
}

void        print_chainedlist(t_var *var)
{
    void    *l;

    l = var;
    ft_printf("the state of the chained list is\n");
    while (var != NULL)
    {
        ft_printf("%s=%s\n", var->key, var->value);
        var = var->prev;
    }
    var = l;
}

void        pop_var(t_var *var)
{
}

int         is_a_var(t_shell *shell, char *line)
{
    int i;
    int r;

    r = 0;
    i = 1;
    while (line[i])
    {
        if (line[i] == '=')
            r++;
        i++;
    }
    if (r == 1)
    {
        shell->var = new_var(shell->var, line);
        print_chainedlist(shell->var);
        return (1);
    }
    return (0);
}
