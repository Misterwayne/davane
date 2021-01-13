/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:18:54 by truepath          #+#    #+#             */
/*   Updated: 2021/01/13 18:57:27 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int		option(char *str)
{
	if ((ft_strcmp(str, "-n")) == 0)
		return (1);
	return (0);
}

char 	*delete_quotes(char *line)
{
	int i;
	int j;
	char symbol;
	char *copy;

	i = 0;
	j = 0;
	copy = malloc(ft_strlen(line));
	symbol = 0;
	while (line[i] != '\0')
	{	
		if ((line[i] == '\'' || line[i]== '\"') && symbol == 0)
			{
				symbol = line[i];
				i++;
			}
		else if (line[i] == symbol)
			{
				symbol = 0;
				i++;
				continue ;
			}
		else
		 copy[j++] = line[i++];
	}
	copy[j] = '\0';
	free(line);
	return (copy);
}

void	print_arguments(char **argv, t_shell *shell)
{
	int		i;
	int		flag;

	i = 1;
	flag = 1;
	if (!(argv[1]) || !(option(argv[1])))
		flag = 0;
	if (flag == 1)
		i = 2;
	if (!(argv[i]) && flag == 0)
		ft_printf("\n");
	while (argv[i])
		{
			ft_printf("%s", argv[i]);
			if (argv[i + 1])
				ft_printf(" ");
			else if (!(argv[i + 1]) && flag == 0)
				ft_printf("\n");
			i++;
		}
}

int		echo(char **argv, t_shell *shell)
{
	int i = 0;
	while (argv[i])
	{
		change_variable(argv[i]);
		argv[i] = delete_quotes(argv[i]);
		i++;
	}
	print_arguments(argv, shell);
	return (0);
}
