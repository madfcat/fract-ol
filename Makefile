CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = fractol
HEADER = ft_fractol.h
LIBFT_DIR = libft/
LIBFT_NAME = libft.a
MLX_DIR = mlx/
MLX_NAME = libmlx.a

SRCS = controls.c fractals.c ft_atod.c init.c main.c render.c texts.c
SRCS_DIR = srcs/
OBJS = $(SRCS:.c=.o)
OBJECTS = $(addprefix $(SRCS_DIR), $(OBJS))

all: $(NAME)

$(NAME): $(SRCS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	mv $(LIBFT_DIR)/$(LIBFT_NAME) .
	mv $(MLX_DIR)/$(MLX_NAME) .
	$(CC) $(MAC_FLAGS) $(CFLAGS) -c $(SRCS) -I $(HEADER)
	mkdir -p $(SRCS_DIR)
	mv $(OBJS) $(SRCS_DIR)
	$(CC) $(MAC_FLAGS) $(CFLAGS) $(MLXFLAGS) $(DEBUGFLAGS) $(OBJECTS) -L. -lft -lmlx -o $(NAME)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(SRCS_DIR)

fclean: clean
	rm -f $(LIBFT_NAME)
	rm -f $(MLX_NAME)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re