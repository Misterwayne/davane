
#include "../../headers/minishell.h"

char    **cat_double_array(char **argv1, char **argv2);

int ft_back_redirection(t_shell *shell, t_fun *fun)
{
    char    **args;
    int     fd;
    char    *str ;
    
    fd =  open (fun->next->argv[0], O_RDONLY);
    fun->next->argv = cat_double_array(fun->prev->argv, fun->next->argv + 1);
    return (fd);
}
