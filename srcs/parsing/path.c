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

char     *launch_from_path(t_shell *shell,char **args, char *cmd)
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
            return(line);
        i++;
        free(line);
    }
    return (0);
}

char    **split_redirection(char **argv, int i)
{
    char    **argv_new;
    int     j;

    j = 0;
    argv_new = malloc(sizeof(char *)*(i + 1));
    while(j < i)
    {
        argv_new[j] = ft_strdup(argv[j]);
        j++;
    }
    argv_new[j] = NULL;
    return (argv_new);
}

int     create_pipe(int *fd)
{
    if(pipe(fd) < 0)
    {
        printf("Can\'t create pipe\n");
        exit(-1); 
    }
    return (0);
}

int   launch_exec(char **args, char *executable, int input, int *output)
{  
    pid_t   pid;
    int     status;

    pid = fork();
    if (pid < 0)
    {
        printf("fork error");
        exit(1);
    }
    if (pid == 0)
    {
        if (input != 0)
            dup2(input, 0);
        if (output)
            dup2(output[1], 1);
        execv(executable, args);
    }
    else
        wait(&status);
    if (input != 0)
        close (input);
    if (output)
    {
        close (output[1]);
        return(output[0]);
    }
    return (0);
}

int     launch_bin(t_shell *shell, char **args, int input)
{
    char    **args_exec;
    char    *executable;
    char    *line = 0;
    int     i = 1;
    int     fd[2];

    while (args[i] != NULL)
    {
        if (ft_strcmp("|", args[i]) == 0)
            {
                args_exec = split_redirection(args, i);
                executable = launch_from_path(shell, args_exec, args_exec[0]);
                create_pipe(fd);
                input = launch_exec(args_exec, executable, input, fd);
                if (args[i + 1])
                    {
                        launch_bin(shell, &args[i + 1], input);
                        return (0);
                    }
                else
                    {
                        args_exec[0] = 0;
                        while (!(args_exec[0]))
                        {
                            ft_printf("pipe> ");
                            get_next_line(0, &line);
                            args_exec = lsh_split_line(line);
                            free(line);
                        }
                        launch_bin(shell, args_exec, input);
                        return (0);
                    }
            }
        i++;
    }
    executable = launch_from_path(shell, args, args[0]);
    launch_exec(args, executable, input, 0);
    return (0);
}