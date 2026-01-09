NAME		= fixed

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp Fixed.cpp

OBJ			= $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): $(OBJ)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "🧹 Cleaning object files..."
	rm -f $(OBJ)

fclean: clean
	@echo "🗑️ Removing executable..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re