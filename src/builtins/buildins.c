/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:33:13 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:24:23 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_run_builtin(t_command *cmd)
{
	if (ft_strcmp(BT_ENV, cmd->command) == 0)
		return (ft_env(cmd));
	else if (ft_strcmp(BT_CD, cmd->command) == 0)
		return (ft_cd(cmd));
	else if (ft_strcmp(BT_EXIT, cmd->command) == 0)
		return (ft_exit(cmd));
	else if (ft_strcmp(BT_EXPORT, cmd->command) == 0)
		return (ft_export(cmd));
	else if (ft_strcmp(BT_UNSET, cmd->command) == 0)
		return (ft_unset(cmd));
	else if (ft_strcmp(BT_ECHO, cmd->command) == 0)
		return (ft_echo(cmd));
	else if (ft_strcmp(BT_PWD, cmd->command) == 0)
		return (ft_pwd(cmd));
	return (127);
}

int	ft_execute_builtin(t_command *cmd)
{
	pid_t	pid;

	if (cmd->in != 0 || cmd->out != 1)
	{
		pid = fork();
		if (pid == 0)
		{
			g_data->exit_flag = 1;
			if (!ft_open_redirs(cmd))
				exit(-1);
			g_data->return_code = ft_run_builtin(cmd);
			ft_close_pipes();
			exit(0);
		}
		return (pid);
	}
	if (!ft_open_redirs(cmd))
		return (-1);
	g_data->return_code = ft_run_builtin(cmd);
	return (-1);
}
