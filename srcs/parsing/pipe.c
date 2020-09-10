#include "../../headers/minishell.h"

int     wait_for_input(t_shell *shell, int input)
{
    char    **args_exec;
    char    *line;

    args_exec[0] = 0;
    line = 0;
    while (!(args_exec[0]))
    {
        ft_printf("pipe> ");
        get_next_line(0, &line);
        args_exec = lsh_split_line(line);
        free(line);
    }
    launch_bin(shell, args_exec, input);
    return (0);
}

int     create_pipe(int *fd)
{
    if(pipe(fd) < 0)
    {
        printf("Can\'t create pipe\n");
        exit(-1); 
    }
    return (0);
}

int		ft_pipe(t_shell *shell, t_fun *fun, int input)
{
	char	**args;
	int		fd[2];
	int		output;
	
	args = lsh_split_line(fun->prev->line);
	create_pipe(fd);
	output = fd[1];
	launch_exec(shell, args, input, output);
	input = fd[0];
	return (input);
}
