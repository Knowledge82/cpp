/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:05:38 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/05 17:10:52 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int	main()
{
	PhoneBook	phonebook;
	std::string	command;

	std::cout << "PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		
		if (std::cin.eof())
		{
			std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
			break;
		}
		if (command == "ADD")
		{
			phonebook.addContact();
		}
		else if (command == "SEARCH")
		{
			phonebook.searchContact();
		}
		else if (command == "EXIT")
		{
			std::cout << "The program quits and the contacts are lost forever!.." << std::endl;
			break;
		}
		else if (!command.empty())
		{
			std::cout << "Error: Invalid command. Available commands: ADD, SEARCH, EXIT" << std::endl;
		}
	}
	return 0;
}
