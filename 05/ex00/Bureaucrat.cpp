/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:27:13 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/16 16:13:24 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Expected range 1-150";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Expected range 1-150";
}
        
Bureaucrat::Bureaucrat() : name_("Default"), grade_(150)
{
	std::cout << "\n*Bureaucrat DEFAULT constructor called*\n" << std::endl;
	std::cout << "Bureaucrat name = " << name_ << std::endl;
	std::cout << "Bureaucrat grade = " << grade_ << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : name_(name), grade_(grade)
{
	std::cout << "\n*Bureaucrat constructor called*\n" << std::endl;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name_(other.name_), grade_(other.grade_)
{
	std::cout << "\n*Bureaucrat COPY constructor called*\n" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "\n*Bureaucrat ASSIGNMENT operator called*\n" << std::endl;
	if (this != &other)
		grade_ = other.grade_;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "\n*Bureaucrat destructor called*\n" << std::endl;
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return os;
}
