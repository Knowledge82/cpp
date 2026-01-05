/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 11:07:23 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/05 12:10:18 by vdarsuye         ###   ########.fr       */
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

#include <cstdlib>
#include <ctime>
#include "functions.hpp"
#include <iostream>

int	main()
{
	srand(time(NULL));

	std::cout << GREEN"============ Generating random objects =============="RESET << std::endl;
	std::cout << "Generating..." << std::endl;
	Base* obj1 = generate();
	Base* obj2 = generate();
	Base* obj3 = generate();
	std::cout << std::endl;

	std::cout << GREEN"============ Identifying via pointer =============="RESET << std::endl;
	std::cout << "Object 1: ";
	identify(obj1);
	std::cout << "Object 2: ";
	identify(obj2);
	std::cout << "Object 3: ";
	identify(obj3);
	std::cout << std::endl;


	std::cout << GREEN"============ Identifying via reference =============="RESET << std::endl;
	std::cout << "Object 1: ";
	identify(*obj1);
	std::cout << "Object 2: ";
	identify(*obj2);
	std::cout << "Object 3: ";
	identify(*obj3);
	std::cout << std::endl;
	
	std::cout << GREEN"============ Deleting objects =============="RESET << std::endl;
	std::cout << "Deleting..." << std::endl;
	delete obj1;
	delete obj2;
	delete obj3;
	std::cout << std::endl;

	return 0;
}
