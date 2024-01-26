SRC = main.c init.c utils.c routine_obs.c routine_philo.c utils_arg.c utils_thread.c
NAME = philo 
FLAGS = -Wall -Wextra -Werror 
CC = gcc -g -pthread
LEAKS = -fsanitize=address  
DATARACE = -fsanitize=thread
COMPIL = ${CC} ${SRC} ${FLAGS} ${DATARACE} -o ${NAME}

all : ${NAME}

$(NAME) : ${SRC}
	${COMPIL}
clean : 
	rm ${NAME}
fclean : 
	@rm -f $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re