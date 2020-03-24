/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 00:12:02 by truepath          #+#    #+#             */
/*   Updated: 2020/03/24 17:14:57 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "../parsing/gnl/get_next_line.h"

int     is_var(char *var, int fd2)
{
    int fd;
    char *line;
    int i;

    if (!(fd = open("var.txt", O_RDONLY)))
        return (0);
    while (get_next_line(fd, &line))
    {
        if (strnstr(line, var, ft_strlen(var)) != NULL)
        {
            write(fd2, "$", 1);
            write(fd2, line, ft_strlen(line));
            write(fd2, "\n", 1);
            return (1);
        }
    }
    close(fd);
    return (0);
}

int     main(int argc, char **argv)
{
    int fd;
    int i;

    i = 1;
    if (!(fd = open("env_var.txt", O_WRONLY | O_CREAT | O_APPEND)))
        return (1);
    if (is_var(argv[1],fd))
        write(1, "varaible ajouter", 17);
    else
            return (1);
    close(fd);
    return (0);
}