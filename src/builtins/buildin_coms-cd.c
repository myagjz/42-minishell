/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buildin_coms-cd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:32:53 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:24:23 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cd(t_command *cmd)
{
	int		error;
	char	*tmp1;
	char	*tmp2;

	if (!cmd->arguments[1])
	{
		tmp1 = ft_get_env(g_data->env[ft_env_index("USER")]);
		tmp2 = ft_strjoin("/Users/", tmp1, ft_strlen(tmp1) + 8);
		chdir(tmp2);
		free(tmp1);
		free(tmp2);
	}
	else
	{
		error = chdir(cmd->arguments[1]);
		if (error)
		{
			ft_put_errno_msg((cmd->arguments[1]));
			return (1);
		}
	}
	update_env_path();
	return (0);
}
