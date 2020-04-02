/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truepath <truepath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 19:15:21 by truepath          #+#    #+#             */
/*   Updated: 2020/03/26 19:44:21 by truepath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

char	**lsh_split_line(char *line)
{
	char **tockens;

	tockens = ft_split(line, ' ');
	return(tockens);
}

void	print_promt(void)// affiche la prompt
{
	char *prompt;

	prompt = "|Minishell| ";
	write(1, prompt, ft_strlen(prompt));
	write(1, ">> :", 3);
	return ;
}

int		load_env(t_env *env)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	if (!(fd = open("data/env_var.txt", O_RDONLY)))
        return (1);
	while (get_next_line(fd, &line))
	{
		env->var[i] = strdup(line);
		i++;
		// free(line);
	}
	env->nb_var = i;
	close(fd);
	return (0);
}

char	*get_value(t_env *env, char *line)
{
	int		i;
	int 	x;
	char	*temp;
	int		value;

	i = 0;
	value = 0;
	while (i < env->nb_var)
	{
		if (strnstr(env->var[i], line, ft_strlen(line) + 1) != NULL)
		{
			value = 1;
			break;
		}
		i++;
	}
	if (value != 0)
		temp = strstr(env->var[i], "=") + 1;
	return (temp);
}

int		check_var(char *line, t_var *var, t_env *env)
{
	int i;
	int fd;

	i = 0;
	if (!(fd = open("data/var.txt", O_RDWR | O_CREAT | O_APPEND, 00700)))
        		return (1);
	while (line[i])// ecrit les variables shell dans une struct et dans un fichier txt
	{			   // uniquement si un '=' est present dans la string
		if (line[i] == '=' && var->nb_var < 20)
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			var->var[var->nb_var] = strdup(line);
			var->nb_var += 1;
			close(fd);
			return (0);
		}
		i++;
	}
	if (line[0] == '$')
		printf("%s\n",get_value(env, line));
	close(fd);
	return (1);
}

void		lsh_loop(void)
{
	char *line;
	char **args;
	t_var vars;
	t_env env; // struct qui contient les variables
	t_cmd cmd; // contient la liste des commande
	int red;
	int on;
	int i;

	i = 0;
	on = 0;
	vars.var = malloc(sizeof(char*) * 20);
	env.var = malloc(sizeof(char*) * 20);
	cmd.cmd_lst =env.var = malloc(sizeof(char*) * 20);
	env.nb_var = 0;
	vars.nb_var = 0;
	load_env(&env);
	load_cmd(&cmd);
	while (on == 0)
	{
		print_promt();
		red = get_next_line(0, &line);
		write(1, "Da !\n", strlen("Da !\n")); // premier parsing
		args = lsh_split_line(line);
		if (check_commande(&cmd, args[0]))
			launch(args[0], args);
		else if (strcmp("exit()", args[0]) == 0)
			on = 1;
		else
			printf("Minishell : Commande not found : %s\n",args[0]);
		free(args);
	}
	free(line);
}

int		main(int argc, char **argv)
{
	lsh_loop();
	return (0);
}