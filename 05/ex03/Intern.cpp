/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:49:57 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/19 19:05:41 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << MAGENTA"* Intern's default constructor called *"RESET << std::endl;
}

Intern::Intern(const Intern& other)
{
	std::cout << MAGENTA"* Intern's copy constructor called *"RESET << std::endl;
	(void)other;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << MAGENTA"* Intern's assign operator called *"RESET << std::endl;
	(void)other;
	return *this;
}

Intern::~Intern()
{

}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	std::string	formNames[] = 
	{
		"shrubbery",
		"robotomy",
		"pardon"
	};

	AForm*	(Intern::*creators[])(const std::string&) = 
	{
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->)
		}
	}

}

AForm*	createShrubberyForm(const std::string& target)
{
	return ShrubberyCreationForm(target);
}

AForm*	createRobotomyForm(const std::string& target)
{
	return RobotomyRequestForm(target);
}

AForm*	createPresidentialForm(const std::string& target)
{
	return PresidentialPardonForm(target);
}


