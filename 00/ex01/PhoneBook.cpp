/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:06:28 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/06 12:11:15 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook()
{
	contactCount = 0;
	oldestIndex = 0;
}

PhoneBook::~PhoneBook()
{

}

void	PhoneBook::addContact()
{
	Contact		newContact;
	std::string	input;

	std::cout << "Adding new contact..." << std::endl;
	
	if (!getInputLine("Enter first name: ", input))
		return;
	newContact.setFirstName(input);

	if (!getInputLine("Enter last name: ", input))
		return;
	newContact.setLastName(input);
	
	if (!getInputLine("Enter nickname: ", input))
		return;
	newContact.setNickname(input);

	if (!getInputLine("Enter phone number: ", input))
		return;
	newContact.setPhoneNumber(input);

	if (!getInputLine("Enter darkest secret: ", input))
		return;
	newContact.setDarkestSecret(input);

	//add contact
	if (contactCount < 8)
	{
		contacts[contactCount] = newContact;
		contactCount++;
	}
	else
	{
		//replace oldest
		contacts[oldestIndex] = newContact;
		oldestIndex = (oldestIndex + 1) % 8;
	}
	std::cout << "Contact added successfully!" << std::endl;
}

void	PhoneBook::searchContact() const
{
	std::string	input;
	int		index;

	if (contactCount == 0)
	{
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}

	displayContactList();

	std::cout << "Enter the index of the contact to display: ";
	std::getline(std::cin, input);

	if (!isValidIndex(input, index))
	{
		std::cout << "Error: Invalid index." << std::endl;
		return;
	}
	displaySingleContact(index);
}

void	PhoneBook::displayContactList() const
{
	int	maxContacts = (contactCount < 8) ? contactCount : 8;
	std::cout << std::setw(10) << std::right << "Index" << "|";
	std::cout << std::setw(10) << std::right << "First Name" << "|";
	std::cout << std::setw(10) << std::right << "Last Name" << "|";
	std::cout << std::setw(10) << std::right << "Nickname" << std::endl;

	for (int i = 0; i < maxContacts; i++)
	{
		std::cout << std::setw(10) << std::right << i << "|";
		std::cout << std::setw(10) << std::right
			<< contacts[i].truncateString(contacts[i].getFirstName(), 10) << "|";
		std::cout << std::setw(10) << std::right
			<< contacts[i].truncateString(contacts[i].getLastName(), 10) << "|";
		std::cout << std::setw(10) << std::right
			<< contacts[i].truncateString(contacts[i].getNickname(), 10) << "|" << std::endl;
	}
}

void	PhoneBook::displaySingleContact(int index) const
{
	if (index >= 0 && index < contactCount)
		contacts[index].displayContact();
	else
		std::cout << "Contact not found!" << std::endl;
}

bool	PhoneBook::getInputLine(const std::string& prompt, std::string& input) const
{
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << std::endl << "EOF. Exiting..." << std::endl;
			return false;
		}
		if (!input.empty())
			return true;

		std::cout << "Field cannot be empty. Please try again" << std::endl;
	}
}

bool	PhoneBook::isValidIndex(const std::string& input, int& index) const
{
	std::stringstream	ss(input);//создаём поток из строки input

	if (!(ss >> index))//пытаемся прочитать int из потока
		return false;
	if (!ss.eof())//проверяем, что дошли до конца строки
		return false;

	return (index >= 0 && index < contactCount);//проверяем диапазон 0-8
}
