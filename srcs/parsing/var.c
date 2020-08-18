/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:15:34 by mwane             #+#    #+#             */
/*   Updated: 2020/08/18 18:44:33 by mwane            ###   ########.fr       */
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
    while (*line != '\0')
        value[j++] = *line++;
    new_node->value = value;
    new_node->next = NULL;
}

void        new_var(t_var *var, char *line)
{
    t_var *new_n;

    new_n = new_node(line);
    var->prev = var->current;
    var->next = new_n;
    var->first = var->next;
    var->current = var->first;
}

void        pop_var(t_var *var)
{
    var->current = var->prev;
    var->current->next = NULL;
}