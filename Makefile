NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = print_char.c \
		print_string.c \
		print_adress.c \
		print_base10.c \
		print_unsi_numb.c \
		print_hexa_in_low.c \
		print_hexa_in_upp.c \
		ft_printf.c 
OBJS = $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean:clean
	rm -f $(NAME)
re:fclean all
.PHONY: all clean fclean re