#include "../../headers/minishell.h"

t_fun	*create_fun(char *data, char *r_symbol)
{
	t_fun	*new;

	new = malloc(sizeof(t_fun));
	new->line = data;
	new->r_symbol = r_symbol; 
	new->l_symbol = 0;
	new->argv = 0;
	new->next = 0;
	new->prev = 0;
	return (new);
}

t_fun	*add_fun(t_fun *fun, char *data, char *r_symbol)
{
	t_fun *tmp;

	tmp = fun;
	if(!(fun)) 
		return (create_fun(data, r_symbol));
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_fun(data, r_symbol);
	tmp->next->prev = tmp;
	return (fun);
}
