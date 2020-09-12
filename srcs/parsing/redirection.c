#include "../../headers/minishell.h"

int   open_file(char *redir, char *file)
{
    int     fd;
    char    *line;
    int     red;
    int     i;

    if (!(file))
        {
            ft_printf("sh:  syntax error near unexpected token `newline\'\n");
            exit(-1);
        }
    if (ft_strcmp(redir, ">>") == 0)
        fd = open(file, O_APPEND | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
    else
        fd = open(file, O_TRUNC | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    return (fd);
}

int   file_to_write(t_shell *shell, t_fun *fun)
{
    char    **args;
	char	*symbol;
    int     fd;
    
    symbol = fun->line;
	fun = fun->next;
    args = lsh_split_line(fun->line);
    fd = open_file(symbol, args[0]);
    return (fd);
}

int	ft_redirection(t_shell *shell, t_fun *fun)
{
	int 	fd;
	char 	**args;
	int		save_output;
	char	*str;
	
	if (!(fun->next))
        {
            ft_printf("sh:  syntax error near unexpected token `newline\'\n");
            exit(-1);
        }
    if (is_special_symbol(fun->next->line) == 1)
    {
        ft_printf("sh:  syntax error near unexpected token ';'\n");
        exit(-1);
    }
    fd = file_to_write(shell, fun);
	str = strcat(fun->prev->line, fun->next->line);
	fun->next->line = fun->prev->line;
	return (fd);
}
