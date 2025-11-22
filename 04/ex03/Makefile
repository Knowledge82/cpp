# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/30 19:02:31 by vdarsuye          #+#    #+#              #
#    Updated: 2025/08/31 18:24:18 by vdarsuye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ff

CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = AMateria.cpp Character.cpp Ice.cpp Cure.cpp MateriaSource.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Makefile AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
