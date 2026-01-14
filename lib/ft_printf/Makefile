NAME = libftprintf.a
CC = cc
FLAG = -Wall -Wextra -Werror

SRC = ft_error.c ft_handle.c ft_printf.c ft_type.c ft_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(FLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re