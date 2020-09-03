/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:01:32 by mwane             #+#    #+#             */
/*   Updated: 2020/09/03 20:15:35 by davlasov         ###   ########.fr       */
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

int     wait_for_input(t_shell *shell, int input)
{
    char    **args_exec;
    char    *line;

    args_exec[0] = 0;
    line = 0;
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


int   open_file(char *redir, char *file)
{
    int     fd;
    char    *line;
    int     red;
    int     i;

    if (!(file))
        {
            ft_printf("parse error near \'\\n\n");
            exit(-1);
        }
    if (ft_strcmp(redir, ">>") == 0)
        fd = open(file, O_APPEND | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
    else
        fd = open(file, O_TRUNC | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    return (fd);
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
        //close (output[1]);
        return(output[0]);
    }
    return (0);
}

int     launch_bin(t_shell *shell, char **args, int input)
{
    char    **args_exec;
    char    *executable;
    int     i = 0;
    int     fd[2];
    int     fd_file;
    char    buf[5];
    int     output;
    int     status;

    while (args[i] != NULL)
    {
        if (ft_strcmp("|", args[i]) == 0)
            {
                args_exec = split_redirection(args, i);
                executable = launch_from_path(shell, args_exec, args_exec[0]);
                create_pipe(fd);
                output = launch_exec(args_exec, executable, input, fd);
                close(fd[1]);                
                if (args[i + 1])
                    return (launch_bin(shell, &args[i + 1], output));
                else
                    return (wait_for_input(shell, output));
            }
        if (ft_strcmp(">", args[i]) == 0 || ft_strcmp(">>", args[i]) == 0)
            {
                fd_file = open_file(args[i], args[i + 1]);
                args_exec = split_redirection(args, i);
                executable = launch_from_path(shell, args_exec, args_exec[0]);
                create_pipe(fd);
                char *args_cat[] = { "/bin/cat", 0, 0};           
                if (input != 0)
                    output = launch_exec(args_cat, "/bin/cat", input, fd);
                output = launch_exec(args_exec, executable, 0, fd);               
                close (fd[1]);
                if (args[i + 1])
                    {
                        //dup2(fd_file, 0);
                        //args[i + 1] = ft_strdup("cat");
                        return (launch_bin(shell, &args[i + 1], output));
                    }
                else
                    return (0);
                // args_exec = split_redirection(args, i);
                // args_exec[0] = executable;
                // args_exec[1] = 0;
                // fd[1] = open_file(args[i], args[i + 1]);
                // if (!(args[i + 2]))
                //     launch_exec(args_exec, executable, output, fd);
                // else
                //     {
                //         args[i + 1] = ft_strdup("cat");
                //         launch_bin(shell, &args[i + 1], output)
                //     }
                //output = launch_exec(args_exec, executable, input, fd);
                // if (fork() == 0)
                //     {
                //         dup2(fd_file, fd[0]);
                //         dup2(fd_file, fd[1]);
                //         if (input == 0)
                //             {
                //                 args_exec = split_redirection(args, i);
                //                 executable = launch_from_path(shell, args_exec, args_exec[0]);
                //             }
                //         output = launch_exec(args_exec, executable, input, fd);
                //     }
                // else
                //     wait(&status);
                //fd[1] = open_file(args[i], args[i + 1]);
                //fd[0] = dup(fd[1]);
                // read(fd_file, buf, 5);
                // ft_printf("CHECKKKK");
                // ft_printf("%s", buf);
                // input_copy = dup(input);
                // if (!(args[i + 2]))
                //     return (0);
                // else
                //     launch_bin(shell, &args[i + 2], input_copy);
            }
        i++;
    }
    executable = launch_from_path(shell, args, args[0]);
    launch_exec(args, executable, input, 0);
    return (0);
}
