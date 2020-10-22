# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwane <mwane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/07 17:46:04 by davlasov          #+#    #+#              #
#    Updated: 2020/08/18 17:47:19 by mwane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  minishell
FILES = srcs/parsing/*.c 
GNL =   srcs/parsing/gnl/*.c
BULITIN =	srcs/builtin/ft_echo.c \
			srcs/builtin/ft_env.c \
			srcs/builtin/export.c \
			srcs/builtin/ft_unset.c \
			srcs/builtin/pwd.c \
			srcs/builtin/cd.c \
			srcs/builtin/ft_exit.c

FLAGS	= -Wall -Werror -Wextra

LIBRARY = libft/libft.a printf/libftprintf.a

all: 	compile

compile: libraries
			gcc $(FLAGS) $(FILES) $(BULITIN) $(GNL) -o $(NAME) -L. $(LIBRARY)
libraries:
			$(MAKE) -C ./libft
			$(MAKE) -C ./printf


clean: 
			rm -rf $(NAME)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all