/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:15:21 by truepath          #+#    #+#             */
/*   Updated: 2021/01/06 18:18:24 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

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
			exit(-1);
		free(line);
	}
}

int		main(int argc, char **argv, char **env)
{
	t_shell	shell;
	t_cmd	cmd;
	
	(void)argc;
	(void)argv;
	load_env(env, &shell);
	load_usr(env, &shell);
	load_cmd(&cmd, &shell);
	lsh_loop(&shell);
	return (0);
}
