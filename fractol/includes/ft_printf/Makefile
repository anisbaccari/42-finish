NAME = libftprintf.a

SRCS = ft_printf.c ft_string.c ft_numbers.c ft_hexa.c ft_char.c ft_pointer.c 

SRC = $(addprefix src/, $(SRCS))

LIBSRCS = libft/*.c      #libft/ft_itoa.c 

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

LIBOBJ =  ${LIBSRCS:.c=.o}

${NAME}: libft ${OBJ} 
		@ar -rcs ${NAME} ${OBJ} ${LIBOBJ}
		@ranlib ${NAME}
		

all: ${NAME}

%.o: %.c
		gcc ${FLAGS} -g -I includes/  -c $< -o ${<:.c=.o}

clean:
		@rm -rf ${OBJ} ${LIBOBJ}
		@make -C libft clean

fclean: clean
		@rm -rf ${NAME}
		@make fclean -C libft
	
libft:
		@make -C libft bonus

re: fclean all

test: re clean
		gcc -g -I includes/ main.c libftprintf.a

.PHONY: all re clean fclean libft test