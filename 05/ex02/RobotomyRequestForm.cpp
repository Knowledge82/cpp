/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:41:31 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/21 11:57:23 by vdarsuye         ###   ########.fr       */
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

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), target_(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), target_(other.target_)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target_ = other.target_;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void	RobotomyRequestForm::executeAction() const
{
	std::cout << YELLOW"* BRRRRR DRRRR BZZZZ (and other drill sounds)*"RESET << std::endl;
	if (std::rand() % 2)
		std::cout << target_ << " has been robotomized " << NEON_GREEN << "successfully"RESET << std::endl;
	else
		std::cout << "Robotomy " << RED"failed"RESET << " on " << target_ << std::endl;
}

