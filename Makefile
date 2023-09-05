# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/05 11:04:31 by evportel          #+#    #+#              #
#    Updated: 2023/09/05 12:23:04 by evportel         ###   ########.fr        #
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
NAME	=	pipex
CC		=	cc
# FLAGS	=	-O3 -Wall -Wextra -Werror
# FLAGS	=	-Wall -Wextra -Werror
FLAGS	=	

SRC		= ${addprefix mandatory/, main.c}

OBJ		= ${SRC:.c=.o}
HEADER	=	include/pipex.h

# RULES MANDATORY ************************************************************ #
all:		${NAME}

${NAME}:	${OBJ}
	@printf "${BLUE}All objects created!${RESET}\n"
	cc ${FLAGS} -Iinclude ${OBJ} -L./libraries/ -lftprintf -o $@
	@printf "${GREEN}${NAME} created!${RESET}\n"
	@exit 0

%.o: %.c
	printf "${YELLOW}Compiling: ${CYAN}${notdir $<}${RESET}\n"
	cc ${FLAGS} -Iinclude -c $< -o $@

# CLEANING RULES ************************************************************* #
clean:
	rm -fr ${OBJ}
	rm -fr ${OBJ_BONUS}
	@printf "${MAGENTA}All objects removed!${RESET}\n"

fclean:		clean
	rm -fr ${NAME}
	rm -fr ${NAME_BONUS}
	@printf "${RED}${NAME} removed!${RESET}\n"

re:			fclean ${NAME}

.PHONY: all bonus clean fclean re