/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:36:55 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/17 12:36:55 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_add_arr_redir(t_redir ***arr, t_redir *new)
{
	ft_add_arr((void ***)arr, (void *)new);
}

void	ft_add_arr_pipeline(t_command ***arr, t_command *new)
{
	ft_add_arr((void ***)arr, (void *)new);
}
