#include "../../headers/minishell.h"

char    **line_replacement(t_shell *shell, char **argv)
{
	int i;

    i = 0;
    while (argv[i])
	{
		//argv[i] = dollar(argv[i], shell->env);
        argv[i] = delete_quotes(argv[i]);
		//ft_printf("%s\n", argv[i]);
		i++;
	}
    return (argv);
}

void     prepare_exec(t_shell *shell, t_lines *lst_lines)
{
    
    int i = 0;
    
    //lst_lines->line = dollar(lst_lines->line, shell->env);
    if (!(lst_lines->argv))
        lst_lines->argv = ft_split_argv(lst_lines->line, shell);
    //lst_lines->argv = line_replacement(shell, lst_lines->argv);
    lst_lines->cmd = lst_lines->argv[0];
    lst_lines->executable = add_path(shell, lst_lines->cmd);
    lst_lines->index = check_commande(shell->cmd, lst_lines->cmd);
    // while (lst_lines->argv[i])
    //     ft_printf("%s\n", lst_lines->argv[i++]);
    // need to check if it is possible to execute this
}
