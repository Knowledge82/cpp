/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 17:13:29 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/19 18:15:48 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <ostream>

class AForm;

class	Bureaucrat
{
public:
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	const std::string&	getName() const;
	int			getGrade() const;

	void			incrementGrade();
	void			decrementGrade();
	void			signForm(AForm& form);
	void			executeForm(const AForm& form) const;
};
private:
	const std::string	name_;
	int			grade_;

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
