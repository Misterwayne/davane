/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:17:08 by truepath          #+#    #+#             */
/*   Updated: 2020/03/26 19:39:47 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int launch(char *prog, char **argv)
{
	pid_t pid;

	pid = fork();
	if (pid < 0)
	{
		perror("fork failed");
		exit(1);
	}
	if (pid == 0)
		execvp(prog, argv);
	else
		waitpid(pid, NULL, 0);
	return (0);
}