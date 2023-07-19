/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:34:06 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:24:23 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	*ft_error_command_arr(t_command **commands, t_token *token)
{
	ft_free_arr_command(commands);
	if (token)
		ft_redir_error(token);
	return (NULL);
}

void	*ft_return_command_free(t_command *cmd)
{
	ft_free_command(cmd);
	return (NULL);
}

void	*ft_error_pipeline(t_command **command, t_token *token)
{
	ft_free_pipeline(command);
	if (token)
		ft_redir_error(token);
	return (NULL);
}

void	ft_put_error(void)
{
	char	*msg;

	msg = (char *)strerror(errno);
	ft_putstr_fd(msg, 2);
}

void	ft_put_errno_msg(char *msg)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd(": ", 2);
	ft_put_error();
	ft_putendl_fd("", 2);
}
