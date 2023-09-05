# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 11:04:31 by evportel          #+#    #+#              #
#    Updated: 2023/09/05 16:56:33 by evportel         ###   ########.fr        #
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
# FLAGS		=	-Wall -Wextra -Werror
FLAGS		=	
LIBFTPRINTF	= -L ./libraries/ -lftprintf

SRC			=	${addprefix mandatory/, main.c}\
				${addprefix mandatory/, ft_check_param.c}

OBJ			= ${SRC:.c=.o}
HEADER		=	-I ./include/

# RULES MANDATORY ************************************************************ #
all:		${NAME}

${NAME}:	ftprintf ${OBJ}
	@printf "${BLUE}All objects created!${RESET}\n"
	${CC} ${FLAGS} -o ${NAME} ${OBJ} ${LIBFTPRINTF} ${HEADER}
#	cc ${FLAGS} -Iinclude ${OBJ} -L./libraries/ -lftprintf -o $@
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0

ftprintf:
	@make -C ./libraries --no-print-directory

%.o: %.c
	@printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	cc ${FLAGS} ${HEADER} -c $< -o $@

# CLEANING RULES ************************************************************* #
clean:
	rm -fr ${OBJ}
	rm -fr ${OBJ_BONUS}
	rm -fr libraries/*.o
	@printf "${MAGENTA}All objects removed!${RESET}\n"

fclean:		clean
	rm -fr ${NAME}
	rm -fr ${NAME_BONUS}
	rm -fr libraries/*.a
	@printf "${RED}${NAME} removed!${RESET}\n"

re:			fclean ${NAME}

# CLEANING RULES ************************************************************* #
test_suite:		re
			clear
			@printf "${CYAN}Recompiling ... OK${RESET}\n"
			@printf "${CYAN}Test File -> Expected OK${RESET}\n"
			./pipex infile "ls -l" "wc -l" outfile
			@printf "${RED}Test File -> Expected ERROR${RESET}\n"
			./pipex args1

.PHONY: all bonus clean fclean re