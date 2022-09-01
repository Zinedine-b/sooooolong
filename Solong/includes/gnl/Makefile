NAME := gnl.a
SRC  := ./get_next_line.c\
			./get_next_line_utils.c\

OBJ = ${SRC:.c=.o}
CC = gcc
rm = rm -rf
FLAGS = -Wall -Wextra -Werror

.c.o:
		${CC} ${CFLAGS} -c $< -o $@

${NAME} :     ${OBJ}
		ar rcs ${NAME} ${OBJ}

all : ${NAME}

clean : 
		${RM} ${OBJ}

fclean :     clean
		${RM} ${NAME}

re    :     fclean ${NAME}

.PHONY: all clean fclean re
