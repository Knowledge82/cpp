/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 17:41:53 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/19 17:49:51 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

class	Intern
{
public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();

	AForm*	makeForm(const std::string& formName, const std::string& target);

private:
	AForm* createShrubberyForm(const std::string& target);
	AForm* createRobotomyForm(const std::string& target);
	AForm* createPresidentialForm(const std::string& target);
};

#endif
