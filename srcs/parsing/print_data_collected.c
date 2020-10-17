
#include "../../headers/minishell.h"


void print_data(t_lines *lst_lines)
{
	t_lines *tmp;
	int n;
	
	n = 1;
	tmp = lst_lines;
	while (tmp)
	{
		ft_printf("%d:", n++);
		if (tmp->line[0] == '\0')
			ft_printf("emply line");
		else
			ft_printf("%s", tmp->line);
		ft_printf("(%s)\n", tmp->symbol);
		if (!(tmp->next))
			return ;
		tmp = tmp->next;
	}
}
