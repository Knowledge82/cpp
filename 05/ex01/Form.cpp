/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:42:18 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/18 15:07:56 by vdarsuye         ###   ########.fr       */
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

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char*	Form::GradeTooHighException::what() const throw()
{
	return CYAN"Grade is too high! Expected range 1-150"RESET;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return CYAN"Grade is too low! Expected range 1-150"RESET;
}

const char*	Form::AlreadySignedException::what() const throw()
{
	return CYAN"Form is already signed"RESET;
}

Form::Form() : name_("Default"), isSigned_(false), gradeToSign_(150), gradeToExecute_(150)
{
	std::cout << MAGENTA"*Default constructor called for " << name_ << "*\n"RESET << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
	std::cout << MAGENTA"*Constructor called for " << name_ << "*\n"RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) :  name_(other.name_), gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_)
{
	isSigned_ = other.isSigned_;
	std::cout << MAGENTA"*Copy constructor called for " << name_ << "*\n"RESET << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << MAGENTA"*Assignment operator called for " << name_ << "*\n"RESET << std::endl;
	if (this != &other)
		isSigned_ = other.isSigned_;
	return *this;
}

Form::~Form()
{
	std::cout << MAGENTA"*Destructor called for " << name_ << "*\n"RESET << std::endl;
}

const std::string&	Form::getName() const
{
	return name_;
}

bool		Form::getIsSigned() const
{
	return isSigned_;
}

int		Form::getGradeToSign() const
{
	return gradeToSign_;
}

int		Form::getGradeToExecute() const
{
	return gradeToExecute_;
}

void		Form::beSigned(const Bureaucrat& b)
{
	if (isSigned_)
		throw Form::AlreadySignedException();
	if (b.getGrade() > gradeToSign_)
		throw Form::GradeTooLowException();
	isSigned_ = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << "Form name: " << f.getName() << std::endl;
	os << "Is form signed? " << (f.getIsSigned() ? "true" : "false") << std::endl;
	os << "Required grade for sign the form: " << f.getGradeToSign() << std::endl;
	os << "Required grade for execute the form: " << f.getGradeToExecute() << std::endl;
	return os;
}
