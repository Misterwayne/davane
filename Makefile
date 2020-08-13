# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mwane <mwane@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/07 17:46:04 by davlasov          #+#    #+#              #
#    Updated: 2020/08/13 16:11:42 by mwane            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  minishell
FILES = srcs/parsing/*.c srcs/parsing/gnl/*.c 
LIBRARY = libft/libft.a printf/libftprintf.a

all: 	compile

compile: libraries
			gcc $(FILES) -o $(NAME) -L. $(LIBRARY)
libraries:
			$(MAKE) -C ./libft
			$(MAKE) -C ./printf
clean: 
			rm -rf $(NAME)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all