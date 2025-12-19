/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:27:13 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/19 15:17:33 by vdarsuye         ###   ########.fr       */
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
#include <iostream>

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return CYAN"Grade is too high! Expected range 1-150"RESET;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return CYAN"Grade is too low! Expected range 1-150"RESET;
}
        
Bureaucrat::Bureaucrat() : name_("Default"), grade_(150)
{
	std::cout << MAGENTA"*Bureaucrat DEFAULT constructor called*"RESET << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade_(grade)
{
	std::cout << MAGENTA"*Bureaucrat constructor called*"RESET << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_)
{
	std::cout << MAGENTA"*Bureaucrat COPY constructor called*"RESET << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << MAGENTA"*Bureaucrat ASSIGNMENT operator called*"RESET << std::endl;
	if (this != &other)
		grade_ = other.grade_;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << MAGENTA"*Bureaucrat destructor called for " << name_ << "*\n"RESET << std::endl;
}

const std::string&	Bureaucrat::getName() const
{
	return this->name_;
}

int	Bureaucrat::getGrade() const
{
	return this->grade_;
}

void	Bureaucrat::incrementGrade()
{
	if (grade_ == 1)
		throw Bureaucrat::GradeTooHighException();
	grade_ = grade_ - 1;
	std::cout << "\n*Incrementing grade of bureaucrat*\n" << std::endl;
}

void	Bureaucrat::decrementGrade()
{
	if (grade_ == 150)
		throw Bureaucrat::GradeTooLowException();
	grade_ = grade_ + 1;
	std::cout << "\n*Decrementing grade of bureaucrat*\n" << std::endl;
}

void	Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name_ << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << name_ << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(const AForm& form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->name_ << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << name_ << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
