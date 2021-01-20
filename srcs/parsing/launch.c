/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:17:08 by truepath          #+#    #+#             */
/*   Updated: 2021/01/20 16:54:44 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

void			print_data(t_lines *fun);

static int   	open_file(char *symbol, char *file)
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

static void 	redirections(t_lines *lst_lines, char *name, char *symbol)
{
	int input;
	int output;

	input = 0;
	output = 0;
	if (ft_strcmp(symbol, ">") == 0 || ft_strcmp(symbol, ">>") == 0)
		output = open_file(symbol, name);
	if (ft_strchr(symbol, '<'))
		input = open_file(symbol, name);
	if  (input == -1|| output == -1)
		ft_printf("error in opening or creating the file");
	if (lst_lines->input != 0)
		close(lst_lines->input);
	if (input != -1)
		lst_lines->input = input;
	if (output != -1)
		lst_lines->output = output;
}


char			*find_name(t_shell *shell, t_lines *elem, char *prev)
{
	char *tmp;
	char *line;
	char **argv;
	char *name;

	line = ft_strdup(elem->line); // copy of line
    argv = ft_split_argv(line, shell);
	if (argv[1])
		{
			tmp = ft_strjoin(prev, ft_strstr(line, argv[1]));
			free(elem->line);
			elem->line = tmp;
		}
	else 
		{
			free(elem->line);
			elem->line = prev;
		}
	name = dollar(argv[0], shell->env); 
	name = delete_quotes(argv[0]); // dont forget to clean the structure!
	return (name);
}

void 			create_redirections(t_shell *shell, t_lines **lst_lines)
{
	t_lines *tmp;
	char	*str1;
	char	*str2;
	char	*str;
	char	*name;

	ft_printf("OK\n");
	// if (ft_strchr(lst_lines->next->symbol, '>') != 0 || ft_strchr(lst_lines->next->symbol, '<') != 0)
	tmp = *lst_lines;
	str1 = tmp->line;
	while (tmp)
		{
			if (ft_strcmp(tmp->symbol, ">") == 0 || ft_strcmp(tmp->symbol, ">>") == 0 || ft_strcmp(tmp->symbol, "<") == 0)
				{
					// ft_printf("%s, ", tmp->symbol);
					name = find_name(shell, tmp->next, tmp->line);
					redirections(tmp->next, name, tmp->symbol);
					tmp = tmp->next;
					continue; 
				}
			break;
		}
	*lst_lines = tmp; // change the line to execute
}

static int  	create_pipe(t_lines *elem)
{
   int     fd[2];
   
   if (pipe(fd) < 0)
    {
        ft_printf("Can\'t create pipe\n");
        return (-1);
    }
	if (elem->output == 0)
   		elem->output = fd[1];
	else
		close(fd[1]);
	elem->next->input = fd[0];   // next should exist we check previously for it
	return (0);
}

void     		launch(t_shell *shell, t_lines *lst_lines)
{
	while (lst_lines)
	{
		if (ft_strcmp(lst_lines->symbol, ">") == 0)
			create_redirections(shell, &lst_lines); // redrect input and output
		if (ft_strcmp(lst_lines->symbol, "|") == 0) // open pipe
			if (create_pipe(lst_lines) == -1) // it is needed to make a right clearning!
				return ;
		prepare_exec(shell, lst_lines);
		launch_exec(shell, lst_lines);
		lst_lines = lst_lines->next;
	}
}
