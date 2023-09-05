# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evportel <evportel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 10:46:35 by evportel          #+#    #+#              #
#    Updated: 2023/06/27 16:38:59 by evportel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
CC			= cc
FLAGS		= -Wall -Wextra -Werror
RM			= rm -f

SOURCES		= ft_printf.c	ft_printf_utils_1.c	ft_printf_utils_2.c
OBJECTS		= $(SOURCES:%.c=%.o)

all:		$(NAME)	

$(NAME):	$(OBJECTS)
			ar -rcs $(NAME) $(OBJECTS)

%.o:		%.c
			$(CC) $(FLAGS) -I ./ -c $< -o $@
clean:
	$(RM) $(OBJECTS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean	all

.PHONY: re fclean clean all