NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f


SRC = ft_printf.c ft_dispatch.c ft_utils.c \
	  ft_conv_uhexdecimal.c ft_conv_udecimal.c \
	  ft_conv_string.c ft_conv_ptr.c \
	  ft_conv_percentsign.c ft_conv_hexdecimal.c \
	  ft_conv_decimal.c  ft_conv_char.c

OBJ = $(SRC:.c=.o)

HEADER = ft_printf.h


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)


%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
