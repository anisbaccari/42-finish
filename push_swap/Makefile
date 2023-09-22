SRC = push_swap.c utils_index.c utils.c utils_list.c utils_sort.c operations.c mouvement.c split.c utils_arg.c radix.c util_init.c \
 utils_error.c utils_list_arg.c utils_2.c 

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

LEAKS = -fsanitize=address

NAME = push_swap

LIBFT = include/libft/libft.a

DEPENDANCE = make -C include/libft

COMPILE = $(CC) $(CFLAGS) -o $(NAME) -Iinclude/libft -Linclude/libft -lft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(COMPILE) $(OBJ)

$(LIBFT):
	$(DEPENDANCE)

clean:
	rm -rf $(OBJ)
	make -C include/libft clean

fclean: clean
	rm -rf $(NAME)
	make -C include/libft fclean

exe: $(NAME)
	./$(NAME)

re: fclean all
