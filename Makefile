NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror -O3

# sources files
SRCS_DIR = ./srcs/
SRCS_NAME = main.c\
	init.c\
	draw.c\
	mandelbrot.c\
	julia.c\
	burningship.c\
	key_control.c\
	color.c\
	error.c

SRCS = $(addprefix $(SRCS_DIR),$(SRCS_NAME))

# objects files
OBJS_DIR = obj/
OBJS_NAME = $(SRCS_NAME:.c=.o)
OBJS = $(addprefix $(OBJS_DIR),$(OBJS_NAME))

# includes
INCLUDES_FR_DIR = ./includes/
INCLUDES_FR_NAME = fractol.h

# libft
LIBFT_DIR = ./libft/
LIBFT_NAME = libft.a
LIBFT = $(addprefix $(LIBFT_DIR),$(LIBFT_NAME))
LIBFT_FLAGS = -lft -L$(LIBFT_DIR)

# mlx
MLX_DIR = ./minilibx_macos/
MLX_NAME = libmlx.a
MLX = $(addprefix $(MLX_DIR),$(MLX_NAME))
MLX_FLAGS = -lmlx -lm -L$(MLX_DIR) -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR) $(MLX_DIR) $(INCLUDES_FR_DIR)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(MLX_FLAGS) $(LIBFT_FLAGS) -I$(INCLUDES_FR_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) $(OBJS) -o $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(FLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(INCLUDES_FR_DIR) -o $@ -c $<

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@/bin/rm -rf $(OBJS_DIR)

fclean:
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)
re: fclean all
