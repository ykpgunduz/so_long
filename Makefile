NAME		= so_long
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

MLX_DIR		= lib/minilibx
LIBFT_DIR	= lib/libft
PRINTF_DIR	= lib/ft_printf
GNL_DIR		= lib/get_next_line

MLX_LIB		= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_LIB	= -L$(LIBFT_DIR) -lft
PRINTF_LIB	= -L$(PRINTF_DIR) -lftprintf
GNL_LIB		= -L$(GNL_DIR) -lgnl

SRCS  	= src/core/main.c \
		src/core/game_init.c \
		src/map/map_read.c \
		src/map/map_check.c \
		src/map/map_path.c \
		src/map/map_utils.c \
		src/map/map_utils2.c \
		src/graphics/render.c \
		src/graphics/utils_img.c \
		src/input/controls.c \
		src/utils/cleanup.c \
		src/utils/error.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(MLX_DIR):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
	fi

$(NAME): $(MLX_DIR) $(OBJS)
	@make -s -C $(MLX_DIR)
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(PRINTF_DIR)
	@make -s -C $(GNL_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(GNL_LIB) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME)

%.o: %.c includes/so_long.h
	$(CC) $(CFLAGS) -Iincludes -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR) -c $< -o $@

clean:
	@rm -rf $(OBJS)
	@make -s -C $(MLX_DIR) clean
	@make -s -C $(LIBFT_DIR) clean
	@make -s -C $(PRINTF_DIR) clean
	@make -s -C $(GNL_DIR) clean
	@rm -rf obj/

fclean: clean
	@rm -rf $(NAME)
	@make -s -C $(MLX_DIR) clean
	@make -s -C $(LIBFT_DIR) fclean
	@make -s -C $(PRINTF_DIR) fclean
	@make -s -C $(GNL_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
