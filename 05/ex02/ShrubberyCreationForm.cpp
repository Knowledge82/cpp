/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:11:52 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/19 15:20:31 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target_(target)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target_(other.target_)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other); // copy base part
		target_ = other.target_;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream	file;
	file.open((target_ + "_shrubbery").c_str());
	if (!file.is_open())
		throw std::runtime_error("Cannot open file: " + target_ + "_shrubbery");
	file << "       *       " << std::endl;
	file << "      /|\\      " << std::endl;
	file << "     / | \\     " << std::endl;
	file << "    /  |  \\    " << std::endl;
	file << "   /   |   \\   " << std::endl;
	file << "  /____|____\\  " << std::endl;
	file << "       |       " << std::endl;
	file.close(); // <- optional 
}

