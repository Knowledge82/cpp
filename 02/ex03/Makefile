# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/12 15:45:51 by vdarsuye          #+#    #+#              #
#    Updated: 2025/08/20 13:20:04 by vdarsuye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsp
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Fixed.cpp main.cpp Point.cpp bsp.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) Makefile Point.hpp Fixed.hpp
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
