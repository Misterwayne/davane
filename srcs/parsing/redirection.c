#include "../../headers/minishell.h"

int   open_file(char *redir, char *file)
{
    int     fd;
    char    *line;
    int     red;
    int     i;

    if (!(file))
        {
            ft_printf("parse error near \'\\n\n");
            exit(-1);
        }
    if (ft_strcmp(redir, ">>") == 0)
        fd = open(file, O_APPEND | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
    else
        fd = open(file, O_TRUNC | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    return (fd);
}

int   file_to_write(t_shell *shell, t_fun *fun)
{
    char    **args;
	char	*symbol;
    int     fd;
    
    symbol = fun->line;
	if (!(fun->next))
        {
            ft_printf("sh: syntax error near unexpected token \'\\n\'\n");
            exit(-1);
        }
    // else if (ft_strcmp(fun->next->line, ";") == 0 || ft_strcmp(fun->next->line, "|") == 0)
    //     {
    //         ft_printf("sh: syntax error near unexpected token \'%s\' \n", fun->next->line);
    //         exit(-1);
    //     }
	fun = fun->next;
    args = lsh_split_line(fun->line);
    fd = open_file(symbol, args[0]);
    return (fd);
}

void	ft_redirection(t_shell *shell, t_fun *fun)
{
	int 	fd;
	char 	**args;
	int		save_output;
	char	*str;
	
	fd = file_to_write(shell, fun);
	ft_printf("%s", fun->line);
	// str = strcat(fun->prev, fun->next);

	// if (fun->next->next && (ft_strcmp(fun->next->next->line, ">>") == 0  || ft_strcmp(fun->next->next->line, ">") == 0))
	// 	{
	// 		tmp = fun->prev;
	// 		fun = fun->next;
	// 		fun = fun->next;
	// 		fun->prev = tmp;
	// 		close(fd);
	// 		launch_body(shell, fun, 0);
	// 	}
	// else
	// 	{
	// 		save_output = dup(1);
	// 		dup2(fd, 1);
	// 		args = lsh_split_line(fun->prev->line);
	// 		launch_exec(shell, args, 0, 0);
	// 		close(1);
	// 		dup(save_output);
	// 		fun = fun->next;
	// 		fun->prev = 0;
	// 		launch_body(shell, fun, 0);
	// 	}
}
