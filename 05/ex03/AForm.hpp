/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:42:04 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/18 18:48:27 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <ostream>
#include <string>

class	Bureaucrat;

class	AForm
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

	class AlreadySignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
	
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

public:
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	virtual ~AForm();

	const std::string&	getName() const;
	bool			getIsSigned() const;
	int			getGradeToSign() const;
	int			getGradeToExecute() const;

	void			beSigned(const Bureaucrat& b);
	void			execute(const Bureaucrat& executor) const;

protected:
	virtual void		executeAction() const = 0;

private:
	const std::string	name_;
	bool			isSigned_;
	const int		gradeToSign_;
	const int		gradeToExecute_;

};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
