# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 11:04:31 by evportel          #+#    #+#              #
#    Updated: 2023/09/07 11:18:59 by evportel         ###   ########.fr        #
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
			@printf "${CYAN}Test1 ... OK${RESET}\n"
			./pipex input "sort" "grep ea" output

test2:		
			clear
			@printf "\n${CYAN}Test2 ... OK${RESET}\n"
			./pipex input.txt "sort" "grep ea" output

.PHONY: all bonus clean fclean re