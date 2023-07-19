# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myagiz <myagiz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/19 12:27:23 by myagiz            #+#    #+#              #
#    Updated: 2023/07/19 16:24:33 by myagiz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell
CC := gcc
CF := -Wall -Wextra -Werror -I /Users/myagiz/goinfre/homebrew/opt/readline/include -g -ggdb
FILES := $(shell find . -name "*.c")
OBJ := $(FILES:.c=.o)
LIBFT := ./libft/libft.a

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C ./libft
	@$(CC) $(CF) $(OBJ) $(LIBFT) -L /Users/myagiz/goinfre/homebrew/opt/readline/lib -lreadline -o $(NAME)

clean : go
	@rm -rf $(OBJ)

go :
	@rm -rf *.o
	@rm -rf ./obj/*.o

fclean : clean
	@make fclean -C ./libft
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re go

