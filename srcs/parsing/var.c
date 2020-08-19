/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 18:15:34 by mwane             #+#    #+#             */
/*   Updated: 2020/08/18 23:15:38 by truepath         ###   ########.fr       */
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
    return new_node;
}

t_var        *new_var(t_var *var, char *line)
{
    t_var *new_n;

    new_n = new_node(line);
    var->next = new_n;
    new_n->prev = var;

    return new_n; 
}

void        print_chainedlist(t_var *var)
{
    void    *l;

    l = var;
    while (var != NULL)
    {
        printf("%s=%s\n", var->key, var->value);
        var = var->prev;
    }
    var = l;
    printf("%s\n", var->value);
}

void        pop_var(t_var *var)
{

}

int        main(void)
{
    t_var   *list;

    list = new_node("lol=lel");
    list = new_var(list, "lil=pouet");
    list = new_var(list, "ok=ko");
    print_chainedlist(list);
    list = new_var(list, "pok=kopp");
    print_chainedlist(list);
    return 0;
}