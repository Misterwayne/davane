/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/26 17:18:54 by truepath          #+#    #+#             */
/*   Updated: 2021/01/17 16:50:08 by davlasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

int		option(char *str)
{
	if ((ft_strcmp(str, "-n")) == 0)
		return (1);
	return (0);
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
	print_arguments(argv, shell);
	exit(999);
	return (-999);
}
