/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 11:58:49 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/06 12:09:44 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{

}

Contact::~Contact()
{

}

void    Contact::setFirstName(const std::string& name)
{
	firstName = name;
}

void    Contact::setLastName(const std::string& name)
{
	lastName = name;
}

void    Contact::setNickname(const std::string& name)
{
	nickname = name;
}

void    Contact::setPhoneNumber(const std::string& number)
{
	phoneNumber = number;
}

void    Contact::setDarkestSecret(const std::string& secret)
{
	darkestSecret = secret;
}

std::string	Contact::getFirstName() const
{
	return firstName;
}

std::string     Contact::getLastName() const
{
	return lastName;
}

std::string	Contact::getNickname() const
{
	return nickname;
}

std::string	Contact::getPhoneNumber() const
{
	return phoneNumber;
}

std::string	Contact::getDarkestSecret() const
{
	return darkestSecret;
}

void	Contact::displayContact() const
{
	std::cout << "First Name: " << firstName << std::endl;
	std::cout << "Last Name: " << lastName << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << darkestSecret << std::endl;
}

std::string	Contact::truncateString(const std::string& str, size_t width) const
{
	std::string	truncated;

	if (str.length() > width)
	{
		truncated = str.substr(0, width -1);
		truncated = truncated + ".";
		return truncated;
	}
	return str;
}
