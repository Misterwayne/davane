#include "../../headers/minishell.h"

void    catch_signal(int sig)
{
	if (sig == SIGINT)
	{
		write(2, "\n", 1);
		ft_printf("sigint");
		//print_promt();
	}
	if (sig == SIGQUIT)
	{
		//ft_printf("\b\b \b\b");
		ft_printf("quit");
	}
}

void    signal_handling()
{
	if (signal(SIGINT, catch_signal) == SIG_ERR)
		exit(0);
	if (signal(SIGQUIT, catch_signal) == SIG_ERR)
		exit(0);
}
