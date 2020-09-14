
#include "../../headers/minishell.h"

char    **cat_double_array(char **argv1, char **argv2);

int     ft_back_redirection(t_shell *shell, t_fun *fun)
{
    int     fd;
    
    if (!(fun->next))
        {
            ft_printf("sh:  syntax error near unexpected token `newline\'\n");
            exit(-1);
        }
    if ((fd = open(fun->next->argv[0], O_RDONLY)) == -1)
        {
            ft_printf("%s\n", strerror(errno));
            exit (-1);
        }
    fun->next->argv = cat_double_array(fun->prev->argv, fun->next->argv + 1);
    return (fd);
}
