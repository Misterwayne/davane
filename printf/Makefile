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

NAME =  libftprintf.a
FILES =  ft_char.c ft_list.c ft_number.c ft_printf.c ft_string.c ft_write.c ft_x.c ft_x_up.c ft_flags.c
COMPILED = $(FILES:.c=.o)

all: 	$(NAME)

$(NAME): $(COMPILED)
			ar rc ${NAME} $(COMPILED)
.c.o: 
			gcc -c -g -Wall -Wextra -Werror $< -o $@
			
bonus: $(COMPILED) $(BONUS_COMPILED)
			ar rc $(NAME) $(COMPILED) $(BONUS_COMPILED)
clean: 
			rm -rf $(COMPILED) $(BONUS_COMPILED)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all