#include "../../headers/minishell.h"

t_lines	*create_fun(char *data, char *r_symbol)
{
	t_lines	*new;

	new = malloc(sizeof(t_lines));
	new->line = data;
	new->r_symbol = r_symbol; 
	new->l_symbol = 0;
	new->argv = 0;
	new->next = 0;
	new->prev = 0;
	return (new);
}

t_lines	*add_fun(t_lines *lst_lines, char *data, char *r_symbol)
{
	t_lines *tmp;

	if(!(lst_lines)) 
		return (create_fun(data, r_symbol));
	tmp = lst_lines;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_fun(data, r_symbol);
	tmp->next->prev = tmp;
	return (lst_lines);
}
