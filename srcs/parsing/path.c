/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:01:32 by mwane             #+#    #+#             */
/*   Updated: 2020/08/20 19:02:32 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int     launch_from_path(char **env,char **args, char *cmd)
{
    char **paths;
    char *line;
    int     i;

    i = 0;
    if (cmd == NULL)
        return (0);
    while (env[i] != NULL)
    {
        if (ft_strncmp(env[i],"PATH=",5) == 0)
            break;
        i++;
    }
    paths = ft_split((env[i] + 5), ':');
    i = 0;
    while (paths[i] != NULL)
    {
        line = ft_strjoin(paths[i], "/");
        line = ft_strjoin(line, cmd);
        if (open(line, O_RDONLY) != -1)
            return (launch_bin(line, args));
        i++;
        free(line);
    }
    return (0);
}

int     launch_bin(char *line, char **args)
{
    int     i;
    pid_t   pid;

    pid = fork();
    if (pid < 0)
    {
        printf("forck error");
        exit(1);
    }
    if (pid == 0)
        i = execv(line,args);
    else
        waitpid(pid, NULL, 0);
    return i;
}
