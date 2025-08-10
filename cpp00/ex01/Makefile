NAME = phonebook

# Colors
RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
NEON_GREEN = \033[92m
MATRIX_GREEN = \033[38;2;10;255;10m
YELLOW = \033[33m
BLUE = \033[34m

# Compilation and flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Src
SRCDIR = .
OBJDIR = obj
SRC = main.cpp PhoneBook.cpp Contact.cpp
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NEON_GREEN)Compilation done$(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp Makefile Contact.hpp PhoneBook.hpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
