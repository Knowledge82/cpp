/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:06:18 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/17 14:38:11 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET	"\033[0m"
#define RED	"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define NEON_GREEN	"\033[92m"

#include "Bureaucrat.hpp"
#include <iostream>

void	tests()
{
	std::cout << GREEN"\n===================== Bureaucraft tests =====================\n"RESET << std::endl;
	std::cout << "👔 Creating default bureaucrat: " << std::endl;
	Bureaucrat	defBureau;
	std::cout << defBureau << std::endl;
	std::cout << "----------------------\n" << std::endl;

	try
	{
		std::cout << "🤓 Creating valid bureaucrat: " << std::endl;
		Bureaucrat	validBureau("Val Bureau", 77);
		std::cout << validBureau << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "🧟 Creating invalid bureaucrat: invalidBureau(\"\", 77000)" << std::endl;
		Bureaucrat	invalidBureau("", 77000);
		std::cout << invalidBureau << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}
	
	std::cout << "🥴 Creating low grade bureaucrat: " << std::endl;
	Bureaucrat	badBureau("lowOne", 149);
	std::cout << badBureau << std::endl;
	std::cout << "----------------------\n" << std::endl;
	try
	{
		std::cout << "🥴 ⬇️  To low grade bureaucrat: " << std::endl;
		badBureau.decrementGrade();
		std::cout << badBureau << std::endl;
		badBureau.decrementGrade();	
		std::cout << badBureau << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}
	std::cout << "🤩 Creating high grade bureaucrat: " << std::endl;
	Bureaucrat	goodBureau("goodOne", 2);
	std::cout << goodBureau << std::endl;
	std::cout << "----------------------\n" << std::endl;
	try
	{
		std::cout << "🤩 ⬆️  To high grade bureaucrat: " << std::endl;
		goodBureau.incrementGrade();
		std::cout << goodBureau << std::endl;
		goodBureau.incrementGrade();	
		std::cout << goodBureau << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}

	std::cout << GREEN"\n===================== Life time test =====================\n"RESET << std::endl;
	try
	{
		std::cout << "Before constructor" << std::endl;
		Bureaucrat invalid("Oops", 9000);
		std::cout << "After constructor" << std::endl;  // не выведется
	}
	catch (std::exception& e)
	{
		std::cout << "Caught:  " << e.what() << std::endl;
	}
	std::cout << "After catch" << std::endl;

	std::cout << GREEN"\n===================== End of tests =====================\n"RESET << std::endl;
}

int	main()
{
	tests();

	std::cout << GREEN"\n===================== End of main() =====================\n"RESET << std::endl;
	return 0;
}
