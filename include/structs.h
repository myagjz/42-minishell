/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:31:43 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 11:26:18 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_data
{
	int		return_code;
	int		sig_flag;
	int		exit_flag;
	int		pipe_count;
	int		*opened_pipes;
	char	**env;
}	t_data;

typedef struct s_redir
{
	char	*path;
	int		type;
	int		appendmode;
}	t_redir;

typedef struct s_command
{
	char	*command;
	char	**heredoc_delim;
	char	**arguments;
	t_redir	**redirections;
	int		out;
	int		in;
}	t_command;

typedef struct s_token
{
	char	*data;
	int		type;
}	t_token;

#endif
