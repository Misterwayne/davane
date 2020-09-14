#include "../../headers/minishell.h"

int     array_len(char **argv)
{
    int i;
    
    i = 0;
    if (!(argv))
        return (0);
    while (argv[i])
        i++;
    return (i);
}

char **cat_double_array(char **argv1, char **argv2)
{
    char **new;
    int i;
    int i1;
    int i2;
    
    i1 = array_len(argv1);
    i2 = array_len(argv2);
    new = malloc(sizeof(char *) * (i1 + i2 + 1));
    i = 0;
    while (argv1[i])
    {
        new[i] = argv1[i];
        i++;
    }
    i = 0;
    while (argv2[i])
    {
        new[i1 + i] = argv2[i];
        i++;
    }
    new[i1 + i] = 0;
    return (new);
}

int   open_file(char *symbol, char *file)
{
    int     fd;

    if (!(file))
        {
            ft_printf("sh:  syntax error near unexpected token `newline\'\n");
            exit(-1);
        }
    if (ft_strcmp(symbol, ">>") == 0)
        fd = open(file, O_APPEND | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH); 
    else
        fd = open(file, O_TRUNC | O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    return (fd);
}

int	ft_redirection(t_shell *shell, t_fun *fun)
{
	int 	fd;
	char 	**args;
	int		save_output;
	char	*str;
	
	if (!(fun->next))
        {
            ft_printf("sh:  syntax error near unexpected token `newline\'\n");
            exit(-1);
        }
    if (is_special_symbol(fun->next->line) == 1)
    {
        ft_printf("sh:  syntax error near unexpected token ';'\n");
        exit(-1);
    }
    fd = open_file(fun->line, fun->next->argv[0]);
    if (!(fun->prev))
        fun->next->argv = cat_double_array(0, fun->next->argv + 1);
    else
        fun->next->argv = cat_double_array(fun->prev->argv, fun->next->argv + 1);
    return (fd);
}
