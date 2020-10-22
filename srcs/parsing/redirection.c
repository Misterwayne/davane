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
    if (i1 + i2 == 0)
        {
            new[0] = 0;
            return (new);
        }
    i = 0;
    while (i < i1)
    {
        new[i] = argv1[i];
        i++;
    }
    if (i2 == 0)
        new[i] = 0;
    i = 0;
    while (i < i2)
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

int	ft_redirection(t_shell *shell, t_lines *lst_lines)
{
	int 	fd;

    (void)shell;
    fd = open_file(lst_lines->symbol, lst_lines->next->argv[0]);
    lst_lines->next->argv = cat_double_array(lst_lines->argv, lst_lines->next->argv + 1);
    return (fd);
}
