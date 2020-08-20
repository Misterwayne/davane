/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:12:47 by truepath          #+#    #+#             */
/*   Updated: 2020/08/20 17:50:34 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"


int     cd(char **argv, t_shell *shell)
{   
    char  *path;

    path = argv[1];
    if (chdir(path) == -1)
    {
        write(1, "cd: no such file or directory: ", 31);
        write(1, path, strlen(path));
        write(1, "\n", 1);
        return (-1);
    }
    return (0);
}
