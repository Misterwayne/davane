# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwane <mwane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/07 17:46:04 by davlasov          #+#    #+#              #
#    Updated: 2020/08/15 16:33:08 by mwane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  minishell
FILES = srcs/parsing/*.c 
GNL =   srcs/parsing/gnl/*.c
EXEC = 	srcs/fonctions/env.c \
		srcs/fonctions/ft_echo.c \
		srcs/fonctions/ft_env.c \
		srcs/fonctions/export.c \
		srcs/fonctions/ft_unset.c \
		srcs/fonctions/pwd.c \
		srcs/fonctions/cd.c

BIN = $(EXEC:%.c=%)
LIBRARY = libft/libft.a printf/libftprintf.a

all: 	compile

compile: libraries bin
			gcc $(FILES) $(GNL) -o $(NAME) -L. $(LIBRARY)
libraries:
			$(MAKE) -C ./libft
			$(MAKE) -C ./printf

bin : $(BIN)

$(BIN): %: %.c
		gcc $(GNL) $(EXEC)  -o $< -L. $(LIBRARY)

clean: 
			rm -rf $(NAME)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all