NAME		= phonebook

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
SRC			= main.cpp Phonebook.cpp Contact.cpp

OBJ			= $(SRC:.cpp=.o)

GREEN		= \033[0;32m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)Done! ./$(NAME) is ready.$(RESET)"

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	rm -f $(OBJ)

fclean: clean
	@echo "Removing executable..."
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re