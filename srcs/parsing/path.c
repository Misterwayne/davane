/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:01:32 by mwane             #+#    #+#             */
/*   Updated: 2020/09/10 16:25:23 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char     *add_path(t_shell *shell, char **args)
{
    char **paths;
    char *line;
    int     i;
    char *cmd;

    cmd = args[0];
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
    i = 0;
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

int   launch_exec(char **args, char *executable, int input, int output)
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
        if (output != 0)
           dup2(output, 1);
        execv(executable, args);
    }
    else
        wait(&status);
    if (input != 0)
        close (input);
    if (output != 0)
        close (output);
    return (0);
}


int     launch_bin(t_shell *shell, char **args, int input)
{
    return (0);
}

int   file_to_write(t_shell *shell, t_fun *fun)
{
    char    **args;
    int     fd;
    
    if (!(fun->next))
        {
            ft_printf("sh: syntax error near unexpected token \'\\n\'\n");
            exit(-1);
        }
    // else if (ft_strcmp(fun->next->line, ";") == 0 || ft_strcmp(fun->next->line, "|") == 0)
    //     {
    //         ft_printf("sh: syntax error near unexpected token \'%s\' \n", fun->next->line);
    //         exit(-1);
    //     }
    args = lsh_split_line(fun->next->line);
    fd = open_file(fun->line, args[0]);
    fun = fun->next;
    fun->prev = 0;
    return (fd);
}

int     launch_body(t_shell *shell, t_fun *fun, int input)
{
    char **args;
    char *executable;
    int old_output;
    int fd_file;
    t_fun *tmp;
    int fd[2];
    int output;
    
    while (fun)
	{
		if (ft_strcmp(fun->line, ";") == 0)
        {
            if (fun->prev)
            {
                args = lsh_split_line(fun->prev->line);
                executable = add_path(shell, args);
                launch_exec(args, executable, 0, 0);
                fun->prev = 0;
            }
            fun = fun->next;
            fun->prev = 0;
            if (fun)
                return (launch_body(shell, fun, 0));
            return 0;
        }
        else if (ft_strcmp(fun->line, ">") == 0 || ft_strcmp(fun->line, ">>") == 0)
        {
            fd_file = file_to_write(shell, fun);
            if (fun->next->next && (ft_strcmp(fun->next->next->line, ">>") == 0  || ft_strcmp(fun->next->next->line, ">") == 0))
                {
                    tmp = fun->prev;
                    fun = fun->next;
                    fun = fun->next;
                    fun->prev = tmp;
                    close(fd_file);
                    launch_body(shell, fun, 0);
                }
            else
                {
                    old_output = dup(1);
                    dup2(fd_file, 1);
                    args = lsh_split_line(fun->prev->line);
                    executable = add_path(shell, args);
                    launch_exec(args, executable, 0, 0);
                    close(1);
                    dup(old_output);
                    fun = fun->next;
                    fun->prev = 0;
                    launch_body(shell, fun, 0);
                }
            return (0);
        }
        else if (ft_strcmp(fun->line, "|") == 0)
        {
            args = lsh_split_line(fun->prev->line);
            executable = add_path(shell, args);
            create_pipe(fd);
            output = fd[1];
            launch_exec(args, executable, input, output);
            input = fd[0];
        }
        else if (!(fun->next))
        {
            args = lsh_split_line(fun->line);
            executable = add_path(shell, args);
            launch_exec(args, executable, input, 0);
            return (0);
        }
        fun = fun->next;
	}
    return (0);
}
