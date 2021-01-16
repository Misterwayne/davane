#include "../../headers/minishell.h"

void    load_cmd(t_cmd *cmd, t_shell *shell)
{
    cmd->cmd_lst = malloc(sizeof(char*) * 7);

    cmd->cmd_lst[0] = "exit";
    cmd->cmd_lst[1] = "export";
    cmd->cmd_lst[2] = "unset";
    cmd->cmd_lst[3] = "cd";
    cmd->cmd_lst[4] = "pwd";
    cmd->cmd_lst[5] = "env";
    cmd->cmd_lst[6] = "echo";
    cmd->builtin_array[0] = &ft_exit;
    cmd->builtin_array[1] = &export;
    cmd->builtin_array[2] = &unset;
    cmd->builtin_array[3] = &cd;
    cmd->builtin_array[4] = &pwd;
    cmd->builtin_array[5] = &env;
    cmd->builtin_array[6] = &echo;
    cmd->builtin_array[7] = NULL;

    shell->cmd = cmd;
}
