/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:12:47 by truepath          #+#    #+#             */
/*   Updated: 2020/03/23 23:02:55 by truepath         ###   ########.fr       */
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
// 
// int     main(int argc, char **argv)
// {
//     char *str;

//     str = pwd();
//     write(1, str, strlen(str));
//     free(str);
//     while(1);
//     return (0);
// }