# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davlasov <davlasov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/07 17:46:04 by davlasov          #+#    #+#              #
#    Updated: 2019/12/12 12:39:55 by davlasov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  minishell
FILES = srcs/parsing/*.c srcs/gnl/*.c 
LIBRARY = libft/libft.a printf/libftprintf.a

all: 	compile

compile: 
			gcc $(FILES) -o $(NAME) -L. $(LIBRARY)
			
clean: 
			rm -rf $(NAME)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all