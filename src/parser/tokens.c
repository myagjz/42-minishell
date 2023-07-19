/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:36:08 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:24:23 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*ft_get_redir_size(int *i, int type, char chr, int size)
{
	char	arr[3];
	char	arr2[2];

	(*i) += size;
	if (size == 2)
	{
		arr[0] = chr;
		arr[1] = chr;
		arr[2] = '\0';
		return (ft_create_token(ft_strdup(arr), type));
	}
	else
	{
		arr2[0] = chr;
		arr2[1] = '\0';
		return (ft_create_token(ft_strdup(arr2), type));
	}
}

t_token	*ft_redir_token(char *str, int *i)
{
	if (str[*i] == '>' && str[*i + 1] == '>')
		return (ft_get_redir_size(i, RED_APPEND, '>', 2));
	else if (str[*i] == '<' && str[*i + 1] == '<')
		return (ft_get_redir_size(i, HEREDOC, '<', 2));
	else if (str[*i] == '|')
		return (ft_get_redir_size(i, PIPE, '|', 1));
	else if (str[*i] == '>')
		return (ft_get_redir_size(i, RED_CREATE, '>', 1));
	else if (str[*i] == '<')
		return (ft_get_redir_size(i, RED_INPUT, '<', 1));
	else
		return (NULL);
}

t_token	*ft_create_token(char *data, int type)
{
	t_token	*token;

	token = ft_calloc(sizeof(t_token), 1);
	if (!token)
		return (NULL);
	token->data = data;
	token->type = type;
	return (token);
}
