/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 13:41:31 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/19 15:23:43 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << "* BRRRRR DRRRR BZZZZ (and other drill sounds)*" << std::endl;
	if (std::rand() % 2)
		std::cout << target_ << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomy failed on " << target_ << std::endl;
}

