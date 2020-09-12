
#include "../../headers/minishell.h"

int ft_back_redirection(t_shell *shell, t_fun *fun)
{
    char    **args;
    char    *symbol;
    int     fd;
    char    *str ;
    
    symbol = fun->line;
    args = lsh_split_line(fun->next->line);
    fd =  open (args[0], O_RDWR);
    str = strcat(fun->prev->line, fun->next->line);
    fun->next->line = str;
    //ft_printf("%s", fun->next->line);
    return (fd);
}
