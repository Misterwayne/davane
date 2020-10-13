/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/22 17:12:47 by truepath          #+#    #+#             */
/*   Updated: 2020/10/13 21:10:22 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int     pwd(char **argv, t_shell *shell)
{
    char *buff;

    buff = malloc(sizeof(char)* 1024);
    getwd(buff);
    write(1, buff, ft_strlen(buff));
    write(1, "!\n", 2);
    // free(buff);
    return (0);
}