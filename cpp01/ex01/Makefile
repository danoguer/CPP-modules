NAME		= horde

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp \
			  Zombie.cpp \
			  zombieHorde.cpp

OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "🧟‍♂️ Linking $@..."
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "🧹 Removing object files..."
	rm -f $(OBJ)

fclean: clean
	@echo "🗑️ Removing executable (horde)..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re