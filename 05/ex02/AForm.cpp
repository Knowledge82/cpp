/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:54:48 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/18 18:17:19 by vdarsuye         ###   ########.fr       */
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

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const char*	AForm::GradeTooHighException::what() const throw()
{
	return CYAN"Grade is too high! Expected range 1-150"RESET;
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return CYAN"Grade is too low! Expected range 1-150"RESET;
}

const char*	AForm::AlreadySignedException::what() const throw()
{
	return CYAN"AForm is already signed"RESET;
}

AForm::AForm() : name_("Default"), isSigned_(false), gradeToSign_(150), gradeToExecute_(150)
{
	std::cout << MAGENTA"*Default constructor called for " << name_ << "*\n"RESET << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute) : name_(name), isSigned_(false), gradeToSign_(gradeToSign), gradeToExecute_(gradeToExecute)
{
	std::cout << MAGENTA"*Constructor called for " << name_ << "*\n"RESET << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) :  name_(other.name_), gradeToSign_(other.gradeToSign_), gradeToExecute_(other.gradeToExecute_)
{
	isSigned_ = other.isSigned_;
	std::cout << MAGENTA"*Copy constructor called for " << name_ << "*\n"RESET << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	std::cout << MAGENTA"*Assignment operator called for " << name_ << "*\n"RESET << std::endl;
	if (this != &other)
		isSigned_ = other.isSigned_;
	return *this;
}

AForm::~AForm()
{
	std::cout << MAGENTA"*Destructor called for " << name_ << "*\n"RESET << std::endl;
}

const std::string&	AForm::getName() const
{
	return name_;
}

bool		AForm::getIsSigned() const
{
	return isSigned_;
}

int		AForm::getGradeToSign() const
{
	return gradeToSign_;
}

int		AForm::getGradeToExecute() const
{
	return gradeToExecute_;
}

void		AForm::beSigned(const Bureaucrat& b)
{
	if (isSigned_)
		throw AForm::AlreadySignedException();
	if (b.getGrade() > gradeToSign_)
		throw AForm::GradeTooLowException();
	isSigned_ = true;
}

void		AForm::execute(const Bureaucrat& executor) const
{
	if (!isSigned_)
		throw FormNotSignedException();
	if (executor.getGrade() > gradeToExecute_)
		throw GradeTooLowException();
	executeAction(); // <- вызов того, что реализует наследник
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << "Form name: " << f.getName() << std::endl;
	os << "Is form signed? " << (f.getIsSigned() ? "true" : "false") << std::endl;
	os << "Required grade for sign the form: " << f.getGradeToSign() << std::endl;
	os << "Required grade for execute the form: " << f.getGradeToExecute() << std::endl;
	return os;
}
