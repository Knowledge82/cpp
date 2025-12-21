/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:01:35 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/21 19:31:06 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{

}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

enum	litType { CHAR, INT, FLOAT, DOUBLE, INVALID, PSEUDO_FLOAT, PSEUDO_DOUBLE };

/* Когда try/catch уместен:
* - Работа с памятью (new может бросить bad_alloc)
* - Файловые операции
* - Критические ошибки
* Для парсинга строки - однозначно if/else! */
litType	detectType(const std::string& lit)
{
	if (isPseudoFloat(lit))
		return PSEUDO_FLOAT;
	if (isPseudoDouble(lit))
		return PSEUDO_DOUBLE;
	if (isChar(lit))
		return CHAR;
	if (isInt(lit))
		return INT;
	if (isFloat(lit))
		return FLOAT;
	if (isDouble(lit))
		return DOUBLE;
	return INVALID;
}

bool	isChar(const std::string& lit)
{
	if (lit.length() == 1 && !std::isdigit(lit[0]))
		return true;
	if (lit.length() == 3 && lit[0] == '\'' && str[2] == '\'')
		return true;
	return false;
}

bool	isInt(const std::string& lit)
{
	if (lit.empty())
		return false;
	size_t i = 0;
	if (lit[0] == '+' || lit [0] == '-')
		i++;
	if (i >= lit.length())
		return false;
	while (i < lit.length())
	{
		if (!std::isdigit(lit[i]))
			return false;
		i++;
	}
	return true;
}

bool	isFloat(const std::string& lit)
{
	if (lit.length() < 3) // min len: .0f = 3 symbols or 5.f = 3 symbols
		return false;

	if (lit[lit.length() - 1] != 'f')
		return false;

	size_t	dotPos = lit.find('.');
	if (dotPos == std::string::npos)
		return false;

	size_t	i = 0;
	if (lit[0] == '+' || lit [0] == '-')
		i++;

	// check before dot
	bool	hasDigitsBeforeDot = false;
	while (i < dotPos)
	{
		if (!std::isdigit(lit[i]))
			return false;
		hasDigitsBeforeDot = true;
		i++;
	}
	i++; // passing dot
	// check after dot
	bool	hasDigitsAfterDot = false;
	while (i < lit.length() - 1)
	{
		if (!std::isdigit(lit[i]))
			return false;
		hasDigitsAfterDot = true;
		i++;
	}
	return (hasDigitsBeforeDot || hasDigitsAfterDot);
}

bool	isDouble(const std::string& lit)
{
	if (lit.length() < 2) // min len: .0 = 2 symbols oor 0. = 2 symbols
		return false;

	size_t dotPos = lit.find('.');
	if (dotPos == std::string::npos)
		return false;

	size_t i = 0;
	if (lit[0] == '+' || lit [0] == '-')
		i++;

	bool	hasDigitsBeforeDot = false;
	while (i < dotPos)
	{
		if (!std::isdigit(lit[i]))
			return false;
		hasDigitsBeforeDot = true;
		i++;
	}
	i++; // passing dot
	
	bool	hasDigitsAfterDot = false;
	while (i < lit.length())
	{
		if (!std::isdigit(lit[i]))
			return false;
		hasDigitsAfterDot = true;
		i++;
	}
	return (hasDigitsBeforeDot || hasDigitsAfterDot);
}

bool	isPseudoFloat(const std::string& lit)
{
	return (lit == "nanf" || lit == "+inff" || lit == "-inff");
}

bool	isPseudoDouble(const std::string& lit)
{
	return (lit == "nan" || lit == "+inf" || lit == "-inf");
}
