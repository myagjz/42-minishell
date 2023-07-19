/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:34:12 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:24:23 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_control_path(t_command *cmd, char *cmdpath)
{
	if (ft_env_index("PATH") != -1 || cmd->command[0] == '/')
		return (cmdpath = find_in_path(cmd->command));
	return (NULL);
}

static int	ft_execute_procc(t_command *cmd)
{
	char	*cmdpath;
	pid_t	pid;

	cmdpath = NULL;
	if (!cmd->command)
	{
		ft_open_redirs(cmd);
		return (-1);
	}
	cmdpath = ft_control_path(cmd, cmdpath);
	pid = -1;
	if (cmdpath)
	{
		if (is_reg_file(cmdpath))
			pid = ft_start_process(cmd, cmdpath);
		else
			ft_file_error(cmd, cmdpath);
	}
	else
	{
		ft_put_err_line("command not found", cmd->command);
		g_data->return_code = 127;
	}
	free(cmdpath);
	return (pid);
}

int	ft_run_command(t_command *cmd)
{
	pid_t	pid;

	ft_parse_quote(cmd);
	if (!(cmd->command))
		return (-1);
	if (ft_builtin_check(cmd->command))
		pid = ft_execute_builtin(cmd);
	else if (!cmd->command)
		pid = ft_execute_redir(cmd);
	else
		pid = ft_execute_procc(cmd);
	return (pid);
}
