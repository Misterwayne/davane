/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:15:21 by truepath          #+#    #+#             */
/*   Updated: 2020/10/17 13:44:18 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void	print_promt(t_shell *shell);

void	get_pwd(t_shell *shell)
{
	int		j;
	char	*path;

	j = 0;
	path = malloc(sizeof(char) * 1024);
	getwd(path);
	j = ft_strlen(path);
	while (path[j] != '/')
		j--;
	shell->current_pwd = (path + (j + 1));
}

void	get_usr(t_shell *shell, char **env)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (env[i])
    {
        if (ft_strncmp(env[i],"USER",4) == 0)
            break;
        i++;
    }
	j = ft_strlen(env[i]);
	while (env[i][j] != '=')
		j--;
	shell->usr = (env[i] + (j + 1));
}

void		lsh_loop(t_shell *shell)
{
	char *line;
	int on;
	
	on = 0;
	while (on == 0)
	{
		print_promt(shell);
		if (get_next_line(0, &line) > 0)
			parse_functions(shell, line);
		free(line);
	}
}

int		main(int argc, char **argv, char **env)
{
	t_env envi; 	// chained list for environnement variable	// chained list struct for the variables
	t_cmd cmd; 		// contient la liste des commandes
	t_shell shell;	// global struct with all the other in it
		// init the chained list, the element "0=0" will always be the last;
	cmd.cmd_lst = malloc(sizeof(char*) * 20);
	load_env(env, &shell);
	load_cmd(&cmd);
	shell.cmd = &cmd;
	shell.enviro = env;
	get_pwd(&shell);
	get_usr(&shell, env);
	lsh_loop(&shell);
	return (0);
}
