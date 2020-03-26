

SRCS	= 	ft_calloc.c \
			ft_isdigit.c \
			ft_memchr.c \
			ft_memset.c \
			ft_strchr.c \
			ft_strjoin.c \
			ft_strncat.c \
			ft_strrchr.c \
			ft_tolower.c \
			ft_isalnum.c \
			ft_isprint.c \
			ft_memcmp.c \
			ft_putstr_fd.c \
			ft_strcmp.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_strstr.c \
			ft_toupper.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_itoa.c \
			ft_memcpy.c \
			ft_putchar_fd.c \
			ft_strcpy.c \
			ft_strlcpy.c \
			ft_strncpy.c \
			ft_strtrim.c \
			ft_bzero.c \
			ft_isascii.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_strcat.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strnstr.c \
			ft_substr.c \
			ft_strmapi.c \

OBJS	= $(SRCS:%.c=%.o)

CFLAGS 	= -Werror -Wextra -Wall

NAME	= libft.a

CC 		= gcc

HEAD	= libft.h


all :
		@make ${NAME}

##test: $(OBJS)
##		@$(CC) $(CFLAGS) -I$(HEAD) $(OBJS) -o test.out

$(NAME)	: $(OBJS)
		@ar rc $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo "LIBFT DONE"
##      @make clean

%.o : %.c
		 @$(CC) $(CFLAGS) -I$(HEAD) -o $@ -c $<

clean:
	@rm -rf $(OBJS)
##	@echo "Removing object file."

fclean:
	@make clean
	@rm -f $(NAME)
##	@echo "${COLOR_RED}Removing bineries"

re:
	@make fclean
##	@echo "${COLOR_BLUE}Compiling :${COLOR_WHITE}"
	@make $(NAME)
