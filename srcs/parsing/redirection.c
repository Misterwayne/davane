#include "../../headers/minishell.h"


int   open_file(char *redir, char *file)
{
    int     fd;
    char    *line;
    int     red;
    int     i;

    if (!(file))
        {
            ft_printf("parse error near \'\\n\n");
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
	if (!(fun->next))
        {
            ft_printf("sh: syntax error near unexpected token \'\\n\'\n");
            exit(-1);
        }
    // else if (ft_strcmp(fun->next->line, ";") == 0 || ft_strcmp(fun->next->line, "|") == 0)
    //     {
    //         ft_printf("sh: syntax error near unexpected token \'%s\' \n", fun->next->line);
    //         exit(-1);
    //     }
	fun = fun->next;
    args = lsh_split_line(fun->line);
    fd = open_file(symbol, args[0]);
    return (fd);
}

int ft_back_redirection(t_shell *shell, t_fun *fun)
{
     char    **args;
    char    *symbol;
    int     fd;
        char    *str ;
    
    symbol = fun->line;
    if (!(fun->next))
        {
            ft_printf("sh: syntax error near unexpected token \'\\n\'\n");
            exit(-1);
        }
    args = lsh_split_line(fun->next->line);
    fd =  open (args[0], O_RDWR);
    str = strcat(fun->prev->line, fun->next->line);
    fun->next->line = str;
    //ft_printf("%s", fun->next->line);
    return (fd);
}

int	ft_redirection(t_shell *shell, t_fun *fun)
{
	int 	fd;
	char 	**args;
	int		save_output;
	char	*str;
	
	fd = file_to_write(shell, fun);
	str = strcat(fun->prev->line, fun->next->line);
	fun->next->line = fun->prev->line;
	return (fd);
	// save_output = dup(1);
	// dup2(fd, 1);
	// close(1);
	// dup(save_output);
	// return (0);
}
