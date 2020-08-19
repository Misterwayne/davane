/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:17:08 by truepath          #+#    #+#             */
/*   Updated: 2020/08/19 13:46:35 by mwane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int		launch(t_shell *shell, int index, char **argv)
{
	pid_t pid;

	
	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	if (pid == 0)// use the index to acces the right function and then passes the argvs 
	{
		if (index > 6)
			return ERROR;
		shell->cmd->builtin_array[index](argv);
	}
	else
		waitpid(pid, NULL, 0);
	return (0);
}