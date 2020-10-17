
#include "../../headers/minishell.h"

char    **cat_double_array(char **argv1, char **argv2);

int     ft_back_redirection(t_shell *shell, t_lines *lst_lines)
{
    int     fd;
    
    if (!(lst_lines->next))
        ft_printf("sh:  syntax error near unexpected token `newline\'\n");
    else if (lst_lines->next->line[0] == '\0')
        ft_printf("sh:  syntax error near unexpected token `newline\'\n");
    if ((fd = open(lst_lines->next->argv[0], O_RDONLY)) == -1)
        {
            ft_printf("%s\n", strerror(errno));
            exit (-1);
        }
    lst_lines->next->argv = cat_double_array(lst_lines->argv, lst_lines->next->argv + 1);
    return (fd);
}
