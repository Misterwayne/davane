
#include "../../headers/minishell.h"

char    **cat_double_array(char **argv1, char **argv2);

int     ft_back_redirection(t_shell *shell, t_fun *fun)
{
    int     fd;
    
    if (!(fun->next))
        ft_printf("sh:  syntax error near unexpected token `newline\'\n");
    else if (fun->next->line[0] == '\0')
        ft_printf("sh:  syntax error near unexpected token `newline\'\n");
    if ((fd = open(fun->next->argv[0], O_RDONLY)) == -1)
        {
            ft_printf("%s\n", strerror(errno));
            exit (-1);
        }
    fun->next->argv = cat_double_array(fun->argv, fun->next->argv + 1);
    return (fd);
}
