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

FLAGS = -Wall -Wextra -Werror

SRC = 	push_swap.c \
		

OBJECTS = $(SRC:.c=.o)

CC = gcc

%.o:%.c		Makefile push_swap.h
			${CC} ${FLAGS} -I ./ -c $< -o $@

$(NAME):	${OBJECTS}
		ar rc ${NAME} ${OBJECTS}

all: $(NAME)

clean:
	rm -rf $(OBJECTS)
fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: 	all clean fclean re