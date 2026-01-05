/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 10:13:01 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/02 12:30:00 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET		"\033[0m"
#define RED		"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"
#define NEON_GREEN	"\033[92m"

#include "ScalarConverter.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./converter <literal>" << std::endl;
		std::cerr << "Note: For char literals, use:  \"'a'\" (with escaped quotes)" << std::endl;
		return 1;
	}
	
	std::cout << "==============================" << std::endl;
	std::cout << GREEN"Input: "RESET << argv[1] << std::endl;
	std::cout << std::endl;
	
	ScalarConverter::convert(argv[1]);
	
	std::cout << "==============================" << std::endl;

/*	else
	{
		std::cout << NEON_GREEN"Interactive mode"RESET << std::endl;
		std::string	input;
		std::cout << "Enter a literal to convert (or 'quit' to exit):" << std::endl;
	 	while (true)
	 	{
	 		std::cout << ">";
	 		std::getline(std::cin, input);
			
	 		if (input == "quit" || std::cin.eof())
	 			break;
			
			std::cout << "Input: " << input << std::endl;
	 
	 		ScalarConverter::convert(input);
	 		std::cout << std::endl;
	  	}
	}
*/
	return 0;
}
