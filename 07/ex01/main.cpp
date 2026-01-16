/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 11:36:25 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/16 13:44:03 by vdarsuye         ###   ########.fr       */
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

#include <string>
#include <iostream>
#include "iter.hpp"

template <typename T>
void	print(T& x)
{
	std::cout << x << "\t";
}

void	increment(int& x)
{
	x++;
}

int	main()
{
	std::cout << std::endl;
	std::cout << GREEN"============== Tests ==============="RESET << std::endl;

	std::cout << "\nPassing array of INT's and print function:"<< std::endl;
	int 		arr1[] = {1, 2, 3, 4, 5};
	::iter(arr1, 5, print<int>);
	std::cout << std::endl;
	
	std::cout << "\nPassing array of CONST INT's and print function:"<< std::endl;
	const int	arrConst[] = {1, 2, 3};
	::iter(arrConst, 3, print<const int>);
	std::cout << std::endl;
	
	std::cout << "\nPassing array of STRING's and print function:"<< std::endl;
	std::string	arrStr[] = {"Hello", "World", "!"};
	::iter(arrStr, 3, print<std::string>);
	std::cout << std::endl;

	std::cout << "\nPassing array of doubles and print function:"<< std::endl;
	double		arr3[] = {1.1, 2.2, 3.3};
	::iter(arr3, 3, print<double>);
	std::cout << std::endl;
	
	std::cout << "\nPassing NULL array and print function:"<< std::endl;
	double		*nullArr = NULL;
	::iter(nullArr, 42, print<double>);
	std::cout << "(empty, as expected)" << std::endl;
	
	std::cout << "\nIncrement case."<< std::endl;
	int		arrInc[] = {1, 2, 3};
	std::cout << "Before: ";
	::iter(arrInc, 3, print<int>);
	std::cout << std::endl;
	::iter(arrInc, 3, increment);
	std::cout << "After: ";
	::iter(arrInc, 3, print<int>);
	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << GREEN"============== End of tests ==============="RESET << std::endl;
	std::cout << std::endl;
	return 0;
}
