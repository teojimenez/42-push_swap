# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teojimen <teojimen@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/12 09:12:22 by teojimen          #+#    #+#              #
#    Updated: 2023/12/12 09:12:22 by teojimen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address

SRC = 	push_swap.c push_swap_utils.c lst_utils.c \
		push_swap_split.c push_swap_operations.c \
		push_swap_moves.c push_swap_moves2.c \
		push_swap_specific_moves.c chunks_sort.c
		

OBJECTS = $(SRC:.c=.o)

CC = gcc

%.o:%.c		Makefile push_swap.h
			${CC} ${FLAGS} -I ./ -c $< -o $@

$(NAME):	${OBJECTS}
		${CC} ${FLAGS} -o ${NAME} ${OBJECTS}
all: $(NAME)

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: 	all clean fclean re