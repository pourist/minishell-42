# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jstrozyk <jstrozyk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 16:51:36 by jstrozyk          #+#    #+#              #
#    Updated: 2024/03/21 15:44:48 by jstrozyk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
SRC			=		src/signals.c src/heredoc.c src/errors.c src/executor.c src/free.c \
						src/pipe.c src/lexer.c src/main.c src/parser.c src/utils.c \
						src/builtins/cd.c src/builtins/echo.c src/builtins/env.c \
						src/builtins/export_utils.c src/builtins/export.c src/builtins/pwd.c \
						src/builtins/set_envp.c src/builtins/unset.c src/builtins/exit.c \
						src/builtins/builtins.c src/handle_red.c src/redirection_parse.c src/path.c
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a
CC = cc
FLAGS = -Wall -Werror -Wextra -g
OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(OBJ): %.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -L$(LIBFT_PATH) -lft -lreadline -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_PATH) all

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: fclean clean all $(LIBFT)
