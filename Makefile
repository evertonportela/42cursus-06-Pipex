# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 11:04:31 by evportel          #+#    #+#              #
#    Updated: 2023/09/07 11:14:10 by evportel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS ********************************************************************* #
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
MAGENTA	=	\033[35m
CYAN	=	\033[36m
RESET	=	\033[0m

# FLAGS MANDATORY ************************************************************ #
NAME		=	pipex
CC			=	cc
# FLAGS		=	-O3 -Wall -Wextra -Werror
FLAGS		=	-Wall -Wextra -Werror
FLAGS		=	
LIBFTPRINTF	= -L ./libraries/libft -lft

SRC			=	${addprefix mandatory/, main.c}

OBJ			=	${SRC:.c=.o}
HEADER		=	-I ./include/

# VARIABLES TEST ************************************************************* #
INPUT_FILE	=	input
COMMAND1	=	"sort"
COMMAND2	=	"grep ea"
OUTPUT_FILE	=	output



# RULES MANDATORY ************************************************************ #
all:		${NAME}

${NAME}:	libft ${OBJ}
			@printf "${BLUE}All objects created!${RESET}\n"
			${CC} ${FLAGS} -o ${NAME} ${OBJ} ${LIBFTPRINTF} ${HEADER}
			@printf "${GREEN}${NAME} created!${RESET}\n"
			make clean

libft:
			make -C ./libraries/libft --no-print-directory
			make clean -C ./libraries/libft --no-print-directory

%.o: %.c
			@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
			cc ${FLAGS} ${HEADER} -c $< -o $@

# CLEANING RULES ************************************************************* #
clean:
			rm -fr ${OBJ}
#			rm -fr ${OBJ_BONUS}
			@printf "${MAGENTA}All objects removed!${RESET}\n"

fclean:		clean
			rm -fr ${NAME}
#			rm -fr ${NAME_BONUS}
			@printf "${RED}${NAME} removed!${RESET}\n"

re:			fclean ${NAME}

# TEST RULES ***************************************************************** #
test1:		
			clear
			@printf "${CYAN}Recompiling ... OK${RESET}\n"
			./${NAME} ${INPUT_FILE} ${COMMAND1} ${COMMAND2} ${OUTPUT_FILE}

.PHONY: all bonus clean fclean re