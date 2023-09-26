NAME = libftprintf.a

SRC = ft_itoa.c ft_strlen.c ft_strdup.c ft_printf.c \
ft_handle_num.c ft_printhex.c ft_printptr.c ft_printptr.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re