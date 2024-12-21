
NAME = beta

FLAGS = -Wall -Wextra -Werror #-fsanitize=address

SRCS = src/main.c src/parsing.c src/parsing_utils.c src/errors.c

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

GNL_DIR = 

INCLUDE = inc/beta.h \
		libft/libft.h libft/ft_printf.h libft/get_next_line.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	
$(LIBFT):
	@make -C $(LIBFT_DIR)

%.o : %.c $(INCLUDE) Makefile
	cc $(FLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
