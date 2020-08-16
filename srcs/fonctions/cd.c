/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:12:47 by truepath          #+#    #+#             */
/*   Updated: 2020/08/16 14:25:32 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int     cd(const char *path)
{   
    if (chdir(path) == -1)
    {
        write(1, "cd: no such file or directory: ", 31);
        write(1, path, strlen(path));
        write(1, "\n", 1);
        return (-1);
    }
    
    return (0);
}
