# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 18:46:50 by vdarsuye          #+#    #+#              #
#    Updated: 2025/08/30 12:47:54 by vdarsuye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = animals

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Animal.cpp Dog.cpp Cat.cpp main.cpp WrongAnimal.cpp WrongCat.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Makefile Animal.hpp Dog.hpp Cat.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)
	@echo "Build done 🤤"

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
