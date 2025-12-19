/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:06:18 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/19 16:26:17 by vdarsuye         ###   ########.fr       */
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
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void	tests()
{
	std::cout << GREEN"\n===================== Form tests =====================\n"RESET << std::endl;
	std::cout << GREEN"\n===== Creating bureaucrats for testing forms =====\n"RESET << std::endl;
	std::cout << "🥴 Creating low grade bureaucrat: " << std::endl;
	Bureaucrat	badBureau("lowOne", 142);
	std::cout << badBureau << std::endl;
	std::cout << "----------------------\n" << std::endl;
	
	std::cout << "🤩 Creating high grade bureaucrat: " << std::endl;
	Bureaucrat	goodBureau("goodOne", 3);
	std::cout << goodBureau << std::endl;
	std::cout << "----------------------\n" << std::endl;

	
	std::cout << GREEN"\n===== Creating forms =====\n"RESET << std::endl;
	
	// Shrubbery form
	std::cout << "🪴 Creating shrubbery form: " << std::endl;
	ShrubberyCreationForm	shrub("home");
	std::cout << shrub << std::endl;
	goodBureau.executeForm(shrub);
	goodBureau.signForm(shrub);
	goodBureau.executeForm(shrub);
	badBureau.executeForm(shrub);
	std::cout << "----------------------\n" << std::endl;
	
	// Robotomy form
	std::cout << "🔫 Creating robotomy form: " << std::endl;
	RobotomyRequestForm robot("Marvin");
	std::cout << robot << std::endl;
	goodBureau.executeForm(robot);
	goodBureau.signForm(robot);
	goodBureau.executeForm(robot);
	badBureau.executeForm(robot);
	std::cout << "----------------------\n" << std::endl;

	// Pardon form
	std::cout << "⚖️  Creating pardon form: " << std::endl;
	PresidentialPardonForm pardon("RandomDude");
	std::cout << pardon << std::endl;
	goodBureau.executeForm(pardon);
	goodBureau.signForm(pardon);
	goodBureau.executeForm(pardon);
	badBureau.executeForm(pardon);
	std::cout << "----------------------\n" << std::endl;


	std::cout << GREEN"\n===================== End of tests() =====================\n"RESET << std::endl;
}

int	main()
{
	std::srand(std::time(NULL)); // init rand gen;
	tests();

	std::cout << GREEN"\n===================== End of main() =====================\n"RESET << std::endl;
	return 0;
}
