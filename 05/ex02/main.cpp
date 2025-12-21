/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:06:18 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/21 11:54:56 by vdarsuye         ###   ########.fr       */
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
	std::cout << GREEN"🪴 Creating shrubbery form: "RESET << std::endl;
	ShrubberyCreationForm	shrub("home");
	std::cout << shrub << std::endl;
	std::cout << GREEN"🪴 Trying to execute non signed shrubbery form: "RESET;
	goodBureau.executeForm(shrub);
	std::cout << std::endl;
	goodBureau.signForm(shrub);
	goodBureau.executeForm(shrub);
	badBureau.executeForm(shrub);
	std::cout << "----------------------\n" << std::endl;
	
	// Robotomy form
	std::cout << GREEN"🔫 Creating robotomy form: "RESET << std::endl;
	RobotomyRequestForm robot("Marvin");
	std::cout << robot << std::endl;
	std::cout << GREEN"🔫 Trying to execute non signed robotomy form: "RESET;
	goodBureau.executeForm(robot);
	std::cout << std::endl;
	goodBureau.signForm(robot);
	goodBureau.executeForm(robot);
	badBureau.executeForm(robot);
	std::cout << std::endl;
	std::cout << GREEN"🔫 Multiply execution robotomy form to show 50\% probability of it (set of 10 forms): "RESET << std::endl;
	for (int i = 1; i <= 10; i++)
	{
		std::cout << i << ": "; 
		goodBureau.executeForm(robot);
		std::cout << std::endl;
	}
	std::cout << "----------------------\n" << std::endl;

	// Pardon form
	std::cout << GREEN"⚖️  Creating pardon form: "RESET << std::endl;
	PresidentialPardonForm pardon("RandomDude");
	std::cout << pardon << std::endl;
	std::cout << GREEN"⚖️  Trying to execute non signed pardon form: "RESET;
	goodBureau.executeForm(pardon);
	std::cout << std::endl;
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
