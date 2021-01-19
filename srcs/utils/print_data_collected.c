
#include "../../headers/minishell.h"


void print_data(t_lines *lst_lines)
{
	t_lines 		*tmp;
	struct files	*ff;
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
		ft_printf("(%c)\n", tmp->c);
		if (lst_lines->files)
		{
			ff = lst_lines->files;
			ft_printf("names:");
			while (ff)
			{
				ft_printf("%s-", ff->name);
				ff = ff->next;
			}
			ft_printf("\n");
		}
		//ft_printf("(input: %d)(output: %d)\n", tmp->input, tmp->output);
		tmp = tmp->next;
	}
	//ft_printf("%s\n", tmp);
	ft_printf("--------------------\n");
}
