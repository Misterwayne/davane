
#include "../../headers/minishell.h"

char    **cat_double_array(char **argv1, char **argv2);

void     ft_back_redirection(t_shell *shell, t_lines *lst_lines)
{
    int     fd;
    
    prepare_exec(shell, lst_lines);
    prepare_exec(shell, lst_lines->next);
    if ((fd = open(lst_lines->next->argv[0], O_RDONLY)) == -1)
        {
            ft_printf("%s\n", strerror(errno));
            return ;
        }
    lst_lines->next->argv = cat_double_array(lst_lines->argv, lst_lines->next->argv + 1); // better to change the pointers, not to create a new function
    if (shell->input != 0)
        close(shell->input);

    shell->input = fd; // we need input
}
