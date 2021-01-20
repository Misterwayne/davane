#include "../../headers/minishell.h"

int     check_commande(t_cmd *cmd, char *line)
{
    int i;

    i = 0;
    if (line == NULL)
        return (-3);
    while (cmd->cmd_lst[i] != NULL)
    {
        if (ft_strcmp(cmd->cmd_lst[i], line) == 0)
            return (i);
        i++;
    }
    return (-2);
}

void     prepare_exec(t_shell *shell, t_lines *lst_lines)
{    
    lst_lines->line = dollar(lst_lines->line, shell->env);
    lst_lines->argv = ft_split_argv(lst_lines->line, shell);
    lst_lines->argv = quotes(shell, lst_lines->argv);
    lst_lines->cmd = lst_lines->argv[0];
    lst_lines->executable = add_path(shell, lst_lines->cmd);
    lst_lines->index = check_commande(shell->cmd, lst_lines->cmd);

    // while (lst_lines->argv[i])
    //     ft_printf("%s\n", lst_lines->argv[i++]);
    // need to check if it is possible to execute this
}
