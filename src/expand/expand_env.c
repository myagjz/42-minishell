/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:34:50 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/19 12:24:23 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_expander(char *token)
{
	char	*env;
	char	*env_back;

	while (1)
	{
		env = ft_take_env(token);
		if (!env)
			break ;
		if (ft_strnstr(env, "$?", ft_strlen(env)) && ft_strlen(env) == 2)
		{
			env_back = ft_itoa(g_data->return_code);
			replace_with(&token, env, env_back);
			free(env_back);
		}
		else
		{
			env_back = get_env(env + 1);
			replace_with(&token, env, env_back);
		}
		free(env);
	}
	return (token);
}
