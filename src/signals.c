/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:37:36 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:27:18 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_signalhandler(int sig)
{
	(void)sig;
	if (g_data->sig_flag)
	{
		printf("\n");
		g_data->sig_flag = 0;
		return ;
	}
	g_data->return_code = 1;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	ft_signal(void)
{
	signal(SIGINT, ft_signalhandler);
	signal(SIGQUIT, SIG_IGN);
}
