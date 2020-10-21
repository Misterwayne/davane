#include "../../headers/minishell.h"

void    signal_handling()
{
    if (signal(SIGINT, catch_signal) == SIG_ERR)
        exit(0);
    if (signal(SIGQUIT, catch_signal) == SIG_ERR)
        exit(0);
}

void    catch_signal(int sig)
{
    if (sig == SIGINT)
    {
        write(2, "\n", 1);
        print_promt();
    }
    if (sig == SIGQUIT)
    {
        ft_printf("SIGQUIT\n");
    }
}
