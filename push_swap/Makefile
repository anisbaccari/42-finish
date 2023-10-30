SRC = push_swap.c utils_index.c utils.c utils_list.c utils_sort.c operations.c mouvement.c split.c utils_arg.c radix.c util_init.c \
 utils_error.c utils_list_arg.c utils_2.c 

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

LEAKS = -fsanitize=address

NAME = push_swap





COMPILE = $(CC) $(CFLAGS) -o $(NAME) 

all: $(NAME)

$(NAME): $(OBJ)
	$(COMPILE) $(OBJ)


clean:
	rm -rf $(OBJ)


fclean: clean
	rm -rf $(NAME)
	
exe: $(NAME)
	./$(NAME)

re: fclean all
