/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 15:01:32 by mwane             #+#    #+#             */
/*   Updated: 2020/09/12 18:46:36 by davlasov         ###   ########.fr       */
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

int     launch_body(t_shell *shell, t_fun *fun)
{
    int output = 0;
    int input = 0;
    
    while (fun)
	{
        if (ft_strcmp(fun->line, ";") == 0)
            semicolon(shell, fun, input, output);
        else if (ft_strcmp(fun->line, "|") == 0)
            input = ft_pipe(shell, fun, input);
        else if (ft_strcmp(fun->line, ">") == 0 || ft_strcmp(fun->line, ">>") == 0)
            output = ft_redirection(shell, fun);
        else if (ft_strcmp(fun->line, "<") == 0)
            input = ft_back_redirection(shell, fun);
        if (!(fun->next))
            return (launch_exec(shell, fun->argv, input, output));
        fun = fun->next;
	}
    return (0);
}
