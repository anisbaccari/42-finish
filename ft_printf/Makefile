NAME = libftprintf.a

SRCS = ft_printf.c ft_string.c ft_numbers.c ft_hexa.c ft_char.c ft_pointer.c

SRC = $(addprefix src/, $(SRCS))

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

${NAME}:  ${OBJ}
		@ar -rcs ${NAME} ${OBJ}
		@ranlib ${NAME}
		@make -C libft

all: ${NAME}

%.o: %.c
		cc ${FLAGS} -g -I includes/ -c $< -o ${<:.c=.o}

clean:
		@rm -rf ${OBJ}
		@make -C libft clean

fclean: clean
		@rm -rf ${NAME}
		@make fclean -C  libft
	
libft:
		@make -C libft bonus

re: fclean all

test: re clean
		gcc -g -I includes/ main.c libftprintf.a

.PHONY: all re clean fclean libft test