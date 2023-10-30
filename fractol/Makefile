SRCS = fractol.c src/control.c src/init_struct.c src/utils.c src/utils_fractal.c  src/utils_img.c src/color.c

NAME = fractol

FT_PRINTF = includes/ft_printf

CFLAGS = -L. -lftprintf  -Wall -Wextra -Werror -g3

MLX_ARGS = -lmlx -framework OpenGL -framework AppKit

${NAME}: libftprintf.a ${SRCS} 
		cc ${SRCS} ${CFLAGS} ${MLX_ARGS} -o ${NAME}

all: ${NAME}

%.o: %.c
		cc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
		make -C ${FT_PRINTF} clean

fclean: clean
		rm -rf ${NAME}
		rm -f libftprintf.a
		make -C ${FT_PRINTF} fclean

re: fclean all

libftprintf.a:
		make -j16 -C ${FT_PRINTF} all
		cp includes/ft_printf/libftprintf.a .

test: all
		./${NAME}

exe: 
	./fractol mandelbrot

.PHONY: all re clean fclean ft_printf test