/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:03:33 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/01 13:18:59 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
//#include <fstream>

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : db_(other.db_)
{

}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
		db_ = other.db_;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{

}

void	BitcoinExchange::loadDB(const std::string& filename)
{
	std::ifstream	file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::string	line;
	while (std::getline(file, line))
		std::cout << line << std::endl;

	file.close();
}

void	BitcoinExchange::processInput(const std::string& filename)
{

}

