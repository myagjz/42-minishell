/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:31:15 by myagiz            #+#    #+#             */
/*   Updated: 2023/07/17 14:32:02 by myagiz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define IN_FILE 1
# define OUT_FILE 2

# define DEFAULT "\033[0m"
# define YELLOW "\033[0;33m"

# define BT_ECHO "echo"
# define BT_CD "cd"
# define BT_PWD "pwd"
# define BT_EXIT "exit"
# define BT_EXPORT "export"
# define BT_UNSET "unset"
# define BT_ENV "env"

# define WORD 1
# define PIPE 2
# define RED_APPEND 3
# define RED_CREATE 4
# define RED_INPUT 5
# define HEREDOC 6

#endif
