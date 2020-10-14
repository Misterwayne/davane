
#include "../../headers/minishell.h"


void print_data(t_fun *fun)
{
	t_fun *tmp;

	tmp = fun;
	while (tmp)
	{
		ft_printf("%s ", tmp->line);
		ft_printf("(%s)\n", tmp->r_symbol);
		if (!(tmp->next))
			return ;
		tmp = tmp->next;
	}
}
