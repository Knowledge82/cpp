/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:19:24 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/19 14:21:13 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), target_(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), target_(other.target_)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target_ = other.target_;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::executeAction() const
{
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

