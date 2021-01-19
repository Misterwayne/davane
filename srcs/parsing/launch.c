/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:17:08 by truepath          #+#    #+#             */
/*   Updated: 2021/01/19 11:51:56 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int     create_pipe(t_lines *elem)
{
   int     fd[2];
   
   if(pipe(fd) < 0)
    {
        ft_printf("Can\'t create pipe\n");
        exit(-1); 
    }
   elem->output = fd[1];
   return (fd[0]);
}

void     launch(t_shell *shell, t_lines *lst_lines)
{
	while (lst_lines)
	{
		prepare_exec(shell, lst_lines);
		// if (lst_lines->c == '|')
		// 	create_pipe(lst_lines);
    	launch_exec(shell, lst_lines, 0, 0);
		lst_lines = lst_lines->next;
	}
}
