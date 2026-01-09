# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eledion <eledion@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/27 10:36:36 by eledion           #+#    #+#              #
#    Updated: 2025/11/27 11:03:49 by eledion          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= diamondtrap

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

SRC			= main.cpp \
			  ClapTrap.cpp \
			  ScavTrap.cpp \
			  FragTrap.cpp \
			  DiamondTrap.cpp

OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re