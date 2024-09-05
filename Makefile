

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRCS = game_logic/maps.c game_logic/picture.c game_logic/validate_map.c \
       game_logic/validate_path.c game_logic/so_long.c game_logic/gamecontrols.c \
       get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \ 
	srcs/ft_printf.c \ //add other ft_printf files 

# Object files
OBJS = $(SRCS:.c=.o)

# Executable
NAME = so_long

# Build the executable
all: $(NAME)

# Include directories
INCLUDES = -I. -I./game_logic -I./headers -I./minilibx -I./get_next_line 

# MiniLibX
MLX_DIR = ./mlx
MLX = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit


# Build the executable
$(NAME): $(OBJS) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

# Compile .c files to .o files
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(NAME)

# Rebuild everything
fclean: clean
	rm -f $(NAME)

re: fclean all

# Build the MiniLibX library (if not already built)
$(MLX):
	make -C $(MLX_DIR)

.PHONY: all clean fclean re
