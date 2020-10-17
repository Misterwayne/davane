#include "../../headers/minishell.h"

void   pipe_errors(t_lines *lst_lines)
{
    if (lst_lines->line[0] == '\0')
        write(2, "syntax error near unexpected token `;\'\n", ft_strlen("syntax error near unexpected token `;\'\n"));
}
int     create_pipe(int *fd)
{
    if(pipe(fd) < 0)
    {
        ft_printf("Can\'t create pipe\n");
        exit(-1); 
    }
    return (0);
}

int		ft_pipe(t_shell *shell, t_lines *fun, int input)
{
	int		fd[2];
	int		output;
	
    create_pipe(fd);
	output = fd[1];
    launch_exec(shell, fun->argv, input, output);
	input = fd[0];
	return (input);
}
