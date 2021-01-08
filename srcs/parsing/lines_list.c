#include "../../headers/minishell.h"

char        *replace_line(t_shell *shell, char *line);

t_lines		*create_lst_lines(char *data, char *r_symbol)
{
	t_lines	*new;

	new = malloc(sizeof(t_lines));
	new->line = data;
	new->symbol = r_symbol;
	new->argv = NULL;
	new->executable = NULL;
	new->index = -1;
	new->next = NULL;
	return (new);
}

t_lines	*add_lst_lines(t_lines *lst_lines, char *data, char *r_symbol)
{
	t_lines *tmp;
	
	if(!(lst_lines)) 
		return (create_lst_lines(data, r_symbol));
	tmp = lst_lines;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = create_lst_lines(data, r_symbol);
	return (lst_lines);
}