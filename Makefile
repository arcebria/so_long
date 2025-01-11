NAME := so_long
CFLAGS := -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX := MLX42

# Directorios
LIBFT_DIR := libft

# Incluye las cabeceras de MLX42 y libft
HEADERS := -I ./include -I $(LIBMLX)/include/MLX42/MLX42.h -I $(LIBFT_DIR)

# Librerías
LIBS := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm $(LIBFT_DIR)/libft.a

# Archivos fuente
SRCS := $(shell find ./src -iname "*.c")
OBJS := ${SRCS:.c=.o}

# Regla principal
all: $(NAME)

# Compilación del ejecutable
$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(LIBMLX)/build/libmlx42.a Makefile
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# Compilación de archivos .c a .o
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -c $< -o $@ $(HEADERS)

# Compilación de libft
$(LIBFT_DIR)/libft.a:
	make -C $(LIBFT_DIR)

# Compilación de MLX42
$(LIBMLX)/build/libmlx42.a:
	cmake -B $(LIBMLX)/build -S $(LIBMLX) > /dev/null
	cmake --build $(LIBMLX)/build --target mlx42 > /dev/null

# Limpieza de objetos
clean:
	rm -rf $(OBJS)
	make clean -C $(LIBFT_DIR)

# Limpieza completa
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	rm -rf $(LIBMLX)/build

# Reconstrucción completa
re: fclean all

# Evitar conflictos con archivos llamados igual que las reglas
.PHONY: all clean fclean re

