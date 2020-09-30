/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:01:32 by mwane             #+#    #+#             */
/*   Updated: 2020/09/30 20:12:13 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void    free_2d_array(char **arr)
{
    int i;
    
    i = 0;
    while (arr[i])
    {
        free(arr[i]);
        i++;
    }
}

char     *add_path(t_shell *shell, char **args)
{
    char **paths;
    char *line;
    int     i;
    char *cmd;

    i = 0;
    if (args[0] == NULL)
        return (0);
    while (shell->enviro[i] != NULL)
    {
        if (ft_strncmp(shell->enviro[i],"PATH=",5) == 0)
            break;
        i++;
    }
    paths = ft_split((shell->enviro[i] + 5), ':');
    i = 0;
    while (paths[i] != NULL)
    {
        line = ft_strjoin(paths[i], "/");
        cmd = ft_strjoin(line, args[0]);
        if (open(cmd, O_RDONLY) != -1)
        {
            free(line);
            free_2d_array(paths + i);
            free(paths);
            return(cmd);
        }
        free(line);
        free(cmd);
        i++;
    }
    free_2d_array(paths);
    free(paths);
    return (0);
}
