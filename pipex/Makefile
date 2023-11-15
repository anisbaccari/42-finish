

######################################
# COLOR
######################################

#----TEXT-----

RED = \033[031m
DEF = \033[0m
GREEN= \033[032m
Yellow= \033[33m
Blue= \033[034m
Purple= \033[035m

######################################
#		VARIABLES
######################################

SRCS = pipex.c includes/ft_printf/src/*.c utils.c


SILENT = --no-print-directory
MAKE_SILENT = @make ${SILENT} -C
COMPILE = cc ${SRCS} ${CFLAGS} -o
MAKE_MSG = @printf "\n\t    ${Purple}Makefile : ${RED}${NAME}${DEF}\n\n "

NAME = pipex
FT_PRINTF = includes/ft_printf
DEBUG=  -fsanitize=address
CFLAGS = -L. -lftprintf   -g -Wall -Werror -Wextra 
 

${NAME} : libftprintf.a  ${SRCS}
	clear
	${COMPILE} ${NAME}
	${MAKE_MSG}

######################################
#		RULES	
######################################


#-- Help
help:
	@printf "\t\t${Purple}Makefile help\n"


all: ${NAME}
	
clean :	
	${MAKE_SILENT} ${FT_PRINTF} clean
	@rm -rf ${OBJ}

fclean : clean
	@rm -rf ${NAME}
	@printf "\t\t${Yellow}CLEANED!\n"
	@rm -f libftprintf.a
	${MAKE_SILENT} ${FT_PRINTF} fclean 
	@rm -rf outfile 	#for testing

re : fclean all
	@printf "\t\t${GREEN}REMAKE\n"
	@printf "${DEF}"
	
libftprintf.a:
	${MAKE_SILENT} ${FT_PRINTF} all
	@cp includes/ft_printf/libftprintf.a .

exe : re
	clear
	./${NAME}


.PHONY: all re clean fclean ft_printf test