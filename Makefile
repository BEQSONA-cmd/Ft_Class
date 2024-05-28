# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btvildia <btvildia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/27 22:05:48 by btvildia          #+#    #+#              #
#    Updated: 2024/05/28 21:38:10 by btvildia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= test
HEADER	= ft_class.h
OBJ	= $(SRC:.c=.o)
SRC	= ft_utils.c ft_class.c ft_attributes.c ft_get.c main.c
CC	 = gcc
FLAGS	 = -Wall -Wextra -Werror -g
all: $(NAME)

$(NAME): $(OBJ)
	cc $(FLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
