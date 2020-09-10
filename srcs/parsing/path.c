/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:01:32 by mwane             #+#    #+#             */
/*   Updated: 2020/09/10 18:59:48 by davlasov         ###   ########.fr       */
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

int   launch_exec(t_shell *shell, char **args, int input, int output)
{  
    pid_t   pid;
    int     status;
    char *executable;

    executable = add_path(shell, args);
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


void	ft_redirection(t_shell *shell, t_fun *fun);

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
                launch_exec(shell, args, 0, 0);
            }
        }
        else if (ft_strcmp(fun->line, "|") == 0)
            input = ft_pipe(shell, fun, input);
        else if (ft_strcmp(fun->line, ">") == 0 || ft_strcmp(fun->line, ">>") == 0)
            ft_redirection(shell, fun);
        if (fun->next)
            fun = fun->next;
        else
            {
                args = lsh_split_line(fun->line);
                launch_exec(shell, args, input, 0);
                return (0);
            }
	}
    return (0);
}
