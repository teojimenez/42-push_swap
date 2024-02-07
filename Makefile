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

FLAGS = -Wall -Wextra -Werror -g
# -fsanitize=address

SRC = 	src/push_swap.c src/push_swap_utils.c src/lst_utils.c \
		 src/push_swap_operations.c \
		src/push_swap_moves.c src/push_swap_moves2.c \
		src/specific_nb.c src/chunks_sort.c \
		src/sort_utils.c src/ft_index.c src/to_nb_error.c \
		src/specific_nb_extra.c src/combined_moves.c \
		src/chunks_size.c src/spp_cost.c src/spp_cost2.c \
		src/ft_cost.c src/lst_utils_cost.c src/error.c
		

OBJECTS = $(SRC:.c=.o)

CC = gcc

%.o:%.c		Makefile includes/push_swap.h
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