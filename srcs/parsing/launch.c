/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:17:08 by truepath          #+#    #+#             */
/*   Updated: 2021/01/19 15:54:32 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

static int   open_file(char *symbol, char *file)
{
    int     fd;

    if (ft_strcmp(symbol, ">>") == 0)
        fd = open(file, O_APPEND | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
    else if (ft_strcmp(symbol, ">") == 0)
        fd = open(file, O_TRUNC | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    else
		fd = open(file, O_RDONLY);
	return (fd);
}

static void 	redirections(t_files *files, t_lines *elem)
{
	int input;
	int output;

	input = 0;
	output = 0;
	while (files)
	{
		if (ft_strchr(files->symbol, '>'))
			output = open_file(files->symbol, files->name);
		if (ft_strchr(files->symbol, '<'))
			input = open_file(files->symbol, files->name);
		files = files->next;
	}
	if (elem->input != 0)
		close(elem->input);
	if (input != -1)
		elem->input = input;
	if (output != -1)
		elem->output = output;
	else
		ft_printf("error in opening or creating the file");
}

static int  	create_pipe(t_lines *elem)
{
   int     fd[2];
   
   if (pipe(fd) < 0)
    {
        ft_printf("Can\'t create pipe\n");
        return (-1);
    }
   elem->output = fd[1];
   elem->next->input = fd[0];
   return (0);
}

void     		launch(t_shell *shell, t_lines *lst_lines)
{
	while (lst_lines)
	{
		prepare_exec(shell, lst_lines);
		if (lst_lines->c == '|')
			{
				if (lst_lines->next) // not forking for mulilines
					if (create_pipe(lst_lines) == -1) // it is needed to make a right clearning!
						return ;
			}
		if (lst_lines->files)
			redirections(lst_lines->files, lst_lines);
		launch_exec(shell, lst_lines);
		lst_lines = lst_lines->next;
	}
}
