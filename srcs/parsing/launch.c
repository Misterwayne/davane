/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwane <mwane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:17:08 by truepath          #+#    #+#             */
/*   Updated: 2020/08/16 14:35:26 by mwane            ###   ########.fr       */
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
	if (pid == 0)//replace this part by a selection by key from the array of function
	{
		
		execvp(prog, argv);
	}
	else
		waitpid(pid, NULL, 0);
	return (0);
}