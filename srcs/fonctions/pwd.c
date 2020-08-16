/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:12:47 by truepath          #+#    #+#             */
/*   Updated: 2020/08/16 14:31:32 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int     pwd(int argc, char **argv)
{
    char *buff;

    buff = malloc(sizeof(char)* 1024);
    getwd(buff);
    write(1, buff, ft_strlen(buff));
    free(buff);
    return (0);
}