

#include "../../headers/minishell.h"

void	load_usr(char **env, t_shell *shell)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (env[i])
    {
        if (ft_strncmp(env[i], "USER", 4) == 0)
            break;
        i++;
    }
	j = ft_strlen(env[i]);
	while (env[i][j] != '=')
		j--;
	shell->usr = (env[i] + (j + 1));
}
