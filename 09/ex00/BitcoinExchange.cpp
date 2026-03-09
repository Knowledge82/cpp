/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 13:03:33 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/09 13:31:52 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdexcept>

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
	std::ifstream			file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string				line;
	std::getline(file, line); //ignoring the very first line
	while (std::getline(file, line))
	{
		size_t				pos = line.find(',');
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string			date = line.substr(0, pos);
		std::string			valueStr = line.substr(pos + 1);
		std::istringstream	iss(valueStr);
		double				value;
		iss >> value;
		db_[date] = value;
	}
	file.close();
}

void	BitcoinExchange::processInput(const std::string& filename)
{
	std::ifstream			file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");
	
	std::string				line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		size_t				pos = line.find(" | ");
		if (pos == std::string::npos)
		{
			std::cerr << "Error: bad input => " + line << std::endl;
			continue;
		}
	
		std::string			date = line.substr(0, pos);
		if (!isValidDate(date))
			continue;

		std::string			valueStr = line.substr(pos + 3);
		double				value;
		if (!isValidValue(valueStr, value))
			continue;
		
		try
		{
			double			result = getRate(date) * value;
			std::cout << date << " => " << value << " = " /*<< std::fixed << std::setprecision(2)*/ << result << std::endl;
		}
		catch (std::runtime_error& e)
		{
			std::cerr << e.what() << std::endl;
		}	
	}
}

bool	BitcoinExchange::isValidDate(const std::string& date) const
{
	if ((date.size() != 10) || (date[4] != '-' || date[7] != '-'))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}

	unsigned int	year, month, day;
	char			dash;
	std::istringstream	iss(date);
	if (!(iss >> year >> dash >> month >> dash >> day))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	if (year <= 1900 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::isValidValue(const std::string& value, double& out) const
{
	std::istringstream	iss(value);
	if (!(iss >> out))
	{
		std::cerr << "Error: bad input => " << value << std::endl;
		return false;
	}
	if (out < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}
	if (out > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}
	return true;
}

double	BitcoinExchange::getRate(const std::string& date) const
{
	std::map<std::string, double>::const_iterator it = db_.upper_bound(date);
	if (it == db_.begin())
		throw std::runtime_error("No price info for this date: " + date);
	--it;
	return it->second;
}

