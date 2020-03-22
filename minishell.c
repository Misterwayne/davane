/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:12:47 by truepath          #+#    #+#             */
/*   Updated: 2020/03/22 17:47:55 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


char     *pwd(void)
{
    char *buff;

    buff = malloc(sizeof(char)* 1024);
    getwd(buff);
    return (buff);
}

int     cd(const char *path)
{   
    if (chdir(path) == -1)
    {
        write(1, "cd: no such file or directory: ", 31);
        write(1, path, strlen(path));
        write(1, "\n", 1);
    }
    return (0);
}


int     main(int argc, char **argv)
{
    char *str;


    cd(argv[1]);
    str = pwd();
    write(1, str, strlen(str));
    free(str);
    return 1;
}