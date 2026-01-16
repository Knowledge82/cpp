/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 15:47:25 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/16 10:59:33 by vdarsuye         ###   ########.fr       */
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

#include "templates.hpp"
#include <iostream>

int	main()
{
	std::cout << std::endl;
	std::cout << GREEN"=========== Default tests ============="RESET << std::endl;

	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << std::endl;
	
	std::cout << GREEN"=========== More tests ============="RESET << std::endl;
	
	std::cout << "Float swap case:" << std::endl;
	float x = 1.5f, y = 2.5f;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	::swap(x, y);
	std::cout << "After swap: x = " << x << ", y = " << y << std::endl;
	std::cout << std::endl;

	std::cout << "Char min case:" << std::endl;
	char c1 = 'a', c2 = 'z';
	std::cout << "c1 = " << c1 << ", c2 = " << c2 << std::endl;
	std::cout << ::min(c1, c2) << std::endl;
	std::cout << std::endl;

	std::cout << "Equal int values case:" << std::endl;
	int a1 = 42, b1 = 42;
	std::cout << "a1 = " << a1 << ", b1 = " << b1 << std::endl;
	std::cout << ::max(a1, b1) << std::endl;

	//error of compilation
	//int n1 = 69;
	//double d1 = 666.0;
	//std::cout << ::min(n1, d1);	

	std::cout << std::endl;
	std::cout << GREEN"=========== End of tests ============="RESET << std::endl;
	return 0;
}
