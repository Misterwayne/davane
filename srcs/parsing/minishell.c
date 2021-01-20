/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:15:21 by truepath          #+#    #+#             */
/*   Updated: 2021/01/20 16:05:11 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void		print_data(t_lines *fun);

void		parse_functions(t_shell *shell, char *line)
{
	t_lines 	*lst_lines;

	// line = quotes(line); // it might be not necessary because we are not handeling  multiline commands
	lst_lines = NULL;
	if (parse(line, &lst_lines) == -1)
		return ;
	// if (parse_redirections(lst_lines) == -1)
	// 	return ;
	print_data(lst_lines);
	launch(shell, lst_lines);
	//print_data(lst_lines);
}

void		lsh_loop(t_shell *shell)
{
	char	*line;

	signal_handling();
	while (1)
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
