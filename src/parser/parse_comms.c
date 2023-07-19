/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_comms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:35:42 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:24:23 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_redir_word_token(t_command *cmd, t_token **tokens, int i)
{
	if (!cmd->command)
		cmd->command = ft_strdup(tokens[i]->data);
	ft_add_arr_str(&(cmd->arguments), ft_strdup(tokens[i]->data));
	return (1);
}

int	ft_redir_heredoc(t_command *cmd, t_token **tokens, int *i)
{
	(*i)++;
	if (tokens[*i] && tokens[*i]->type == WORD)
	{
		ft_add_arr_str(&(cmd->heredoc_delim), ft_strdup(tokens[*i]->data));
		return (1);
	}
	ft_redir_error(tokens[*i]);
	return (0);
}

int	ft_redir_input(t_command *cmd, t_token **tokens, int *i)
{
	t_redir	*redir;

	(*i)++;
	if (tokens[*i] && tokens[*i]->type == WORD)
	{
		redir = ft_calloc(sizeof(t_redir), 1);
		redir->type = IN_FILE;
		redir->path = ft_strdup(tokens[*i]->data);
		ft_add_arr_redir(&(cmd->redirections), redir);
		return (1);
	}
	ft_redir_error(tokens[*i]);
	return (0);
}

int	ft_redir_output(t_command *cmd, t_token **tokens, int *i)
{
	t_redir	*redir;

	redir = ft_calloc(sizeof(t_redir), 1);
	if (tokens[*i]->type == RED_APPEND)
		redir->appendmode = 1;
	(*i)++;
	if (tokens[*i] && tokens[*i]->type == WORD)
	{
		redir->type = OUT_FILE;
		redir->path = ft_strdup(tokens[*i]->data);
		ft_add_arr_redir(&(cmd->redirections), redir);
		return (1);
	}
	ft_redir_error(tokens[*i]);
	ft_free_redir(redir);
	return (0);
}
