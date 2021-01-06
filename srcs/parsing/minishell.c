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
	char	*line;
	int		on;
	
	on = 0;
	signal_handling();
	while (on == 0)
	{
		print_promt();
		if (get_next_line(0, &line) > 0)
			parse_functions(shell, line);
		else
			exit(0);
		free(line);
	}
}

int		main(int argc, char **argv, char **env)
{
	t_cmd cmd;
	t_shell shell;
	(void)argc;
	(void)argv;

	cmd.cmd_lst = malloc(sizeof(char*) * 20);
	load_env(env, &shell);
	load_cmd(&cmd);
	shell.cmd = &cmd;
	shell.enviro = env;
	get_usr(&shell, env);
	lsh_loop(&shell);
	return (0);
}
