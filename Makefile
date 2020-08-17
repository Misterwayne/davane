# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwane <mwane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/07 17:46:04 by davlasov          #+#    #+#              #
#    Updated: 2020/08/17 14:04:01 by mwane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  minishell
FILES = srcs/parsing/*.c 
GNL =   srcs/parsing/gnl/*.c
BULITIN =	srcs/fonctions/ft_echo.c \
			srcs/fonctions/ft_env.c \
			srcs/fonctions/export.c \
			srcs/fonctions/ft_unset.c \
			srcs/fonctions/pwd.c \
			srcs/fonctions/cd.c

LIBRARY = libft/libft.a printf/libftprintf.a

all: 	compile

compile: libraries
			gcc $(FILES) $(BULITIN) $(GNL) -o $(NAME) -L. $(LIBRARY)
libraries:
			$(MAKE) -C ./libft
			$(MAKE) -C ./printf


clean: 
			rm -rf $(NAME)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all