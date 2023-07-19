/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:35:21 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:24:23 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_free_command(t_command *cmd)
{
	if (cmd)
	{
		if (cmd->out != 1)
			close(cmd->out);
		if (cmd->in != 0)
			close(cmd->in);
		ft_free_arr_str(cmd->arguments);
		ft_free_arr_str(cmd->heredoc_delim);
		ft_free_arr((void **)cmd->redirections,
			(void (*)(void *))ft_free_redir);
		free(cmd->command);
		free(cmd);
	}
}

void	ft_free_pipeline(t_command **commands)
{
	if (commands)
		ft_free_arr_command(commands);
}

void	ft_free_token(t_token *token)
{
	if (token)
	{
		free(token->data);
		free(token);
	}
}

void	ft_free_arr_token(t_token **tokens)
{
	ft_free_arr((void **)tokens, (void (*)(void *))ft_free_token);
}
