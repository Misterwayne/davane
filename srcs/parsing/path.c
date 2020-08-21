/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:01:32 by mwane             #+#    #+#             */
/*   Updated: 2020/08/21 15:58:07 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int     launch_from_path(t_shell *shell,char **args, char *cmd)
{
    char **paths;
    char *line;
    int     i;

    i = 0;
    if (cmd == NULL)
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
        line = ft_strjoin(line, cmd);
        if (open(line, O_RDONLY) != -1)
            return (launch_bin(line, args, shell));
        i++;
        free(line);
    }
    return (0);
}

int     launch_bin(char *line, char **args, t_shell *shell)
{
    int     i;
    pid_t   pid;

    pid = fork();
    shell->last_pid = pid;
    if (pid < 0)
    {
        printf("forck error");
        exit(1);
    }
    if (pid == 0)
        i = execv(line,args);
    else
    {
        waitpid(pid, NULL, 0);
    }
    shell->last_return = i;
    return i;
}
