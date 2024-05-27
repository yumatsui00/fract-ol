NAME	= fractol

SRCS = src/main.c src/julia.c src/ft_atod.c src/julia_utils.c src/initializer.c \
	src/mandelbrot.c src/mandel_utils.c src/burningship.c src/burningship_utils.c

CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror

MLX_LNK	= -L $(MLX) -l mlx -framework OpenGL -framework AppKit

OBJ = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
