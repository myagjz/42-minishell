/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:33:59 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:24:23 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_put_err_line(char *msg, char *data)
{
	ft_putstr_fd("minishell: ", 2);
	if (data)
	{
		ft_putstr_fd(data, 2);
		ft_putstr_fd(": ", 2);
	}
	ft_putendl_fd(msg, 2);
}

void	ft_redir_error(t_token *token)
{
	if (token)
	{
		ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
		ft_putstr_fd(token->data, 2);
		ft_putstr_fd("'\n", 2);
	}
	else
	{
		ft_putstr_fd("minishell: syntax error near ", 2);
		ft_putstr_fd("unexpected token `newline'\n", 2);
	}
	g_data->return_code = 258;
}

void	ft_file_error(t_command *cmd, char *path)
{
	if (is_file_exist(path))
	{
		ft_put_err_line("is a directory", cmd->command);
		g_data->return_code = 126;
	}
	else
	{
		g_data->return_code = 127;
		ft_put_err_line("No such file or directory", cmd->command);
	}
}
