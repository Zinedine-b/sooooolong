# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zboutabb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 15:04:42 by zboutabb          #+#    #+#              #
#    Updated: 2022/08/30 15:04:45 by zboutabb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

INCLUDES 		:= ./includes
PATH_SRC 		:= ./src

PATH_LIBFT 		:= ${INCLUDES}/libft
libftincludes 	:= ${PATH_LIBFT}/
libft.a 		:= ${PATH_LIBFT}/libft.a

PATH_GNL		:=$(INCLUDES)/gnl
gnlincludes 	:= ${PATH_GNL}/
gnl.a 			:=$(PATH_GNL)/gnl.a

SRC 			:= ./src/main.c\
					./src/utils.c\
					./src/init.c\
					./src/parse.c\
					./src/split_es_tu_la.c\
					./src/draw.c\
					./src/holdkey.c\


OBJS 			:=${SRC:.c=.o}

CFLAG  			:=-Wall -Wextra -Werror #-g -fsanitize=address

CC 				:= gcc
CFLAGS			:=${CFLAG} 
LDLIBS     		:=$(libft.a) ${gnl.a} -lmlx -framework OpenGL -framework AppKit
RM 				:= rm -rf


all:
	@$(MAKE) -j $(NAME)

${NAME}: ${OBJS}
			@$(MAKE) -j -C includes/libft/ bonus
			@$(MAKE) -j -C includes/gnl/
			$(CC) $(LDLIBS) $(CFLAGS) ${OBJS} includes/libft/libft.a includes/gnl/gnl.a -o ${NAME}

%.o : %.c
		${CC} -c ${CPPFLAGS} ${CFLAGS} -o $@ $<

clean:
			@$(MAKE) -s --no-print-directory -C includes/libft/ clean
			@$(MAKE) -s --no-print-directory -C includes/gnl/ clean

			${RM} ${OBJS}

fclean: 	clean
			@$(MAKE) -s --no-print-directory -C includes/libft/ fclean
			@$(MAKE) -s --no-print-directory -C includes/gnl/ fclean
			${RM} ${NAME}

re: 		fclean all
			@$(MAKE) -s --no-print-directory -C includes/libft/ re
			@$(MAKE) -s --no-print-directory -C includes/gnl/ re

.PHONY: all clean fclean re
