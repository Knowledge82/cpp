/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:01:35 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/02 11:55:41 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip> // std::precision
#include <limits> // std::numeric_liimits
#include <cmath> // std::isnan, std::isinf
#include <cctype> // std::isprint

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& other)
{
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

bool	ScalarConverter::isChar(const std::string& literal)
{
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')	// 'a'
		return true;
	if (literal.length() == 1 && !std::isdigit(literal[0]))			// a
		return true;
	return false;
}

bool	ScalarConverter::isInt(const std::string& literal)
{
	if (literal.empty())
		return false;

	char	*end;
	strtol(literal.c_str(), &end, 10);

	return (*end == '\0');
}

bool	ScalarConverter::isFloat(const std::string& literal)
{
	if (literal.empty() || literal[literal.length() - 1] != 'f')
		return false;

	std::string numPart = literal.substr(0, literal.length() - 1); // cut 'f'
	if (numPart.empty() || numPart.find('.') == std::string::npos)
		return false;

	char	*end;
	strtod(numPart.c_str(), &end);

	return (*end == '\0');
}

bool	ScalarConverter::isDouble(const std::string& literal)
{
	if (literal.empty())
		return false;

	if (literal.find('.') == std::string::npos)
		return false;

	char	*end;
	strtod(literal.c_str(), &end);

	return (*end == '\0');
}

bool	ScalarConverter::isPseudo(const std::string& literal)
{
	return (literal == "nanf" || literal == "+inff" || literal == "-inff" ||
		literal == "nan"  || literal == "+inf"  || literal == "-inf");
}

/* Когда try/catch уместен:
* - Работа с памятью (new может бросить bad_alloc)
* - Файловые операции
* - Критические ошибки
* Для парсинга строки - однозначно if/else! */
ScalarConverter::LitType	ScalarConverter::detectType(const std::string& literal)
{
	if (isPseudo(literal))
		return PSEUDO;
	if (isChar(literal))
		return CHAR;
	if (isInt(literal))
		return INT;
	if (isFloat(literal))
		return FLOAT;
	if (isDouble(literal))
		return DOUBLE;
	return INVALID;
}

void	ScalarConverter::convert(const std::string& literal)
{
	LitType type = detectType(literal);

	if (type == INVALID)
	{
		std::cout << "❌ Error: invalid literal" << std::endl;
		return;
	}

	double value = parseToDouble(literal, type);

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

// parse any value in double coz it's the most widest type
double	ScalarConverter::parseToDouble(const std::string& literal, LitType type)
{
	switch (type)
	{
		case CHAR:
			{
				if (literal.length() == 3)
					return static_cast<double>(literal[1]);
				return static_cast<double>(literal[0]);
			}

		case INT:
			return strtod(literal.c_str(), NULL);

		case FLOAT:
		{
			std::string numPart = literal.substr(0, literal.length() - 1);
			return strtod(numPart.c_str(), NULL);
		}

		case DOUBLE:
			return strtod(literal.c_str(), NULL);

		case PSEUDO:
			return parsePseudo(literal);

		default:
			return 0.0;
	}
}

double	ScalarConverter::parsePseudo(const std::string& literal)
{
	if (literal == "nan" || literal == "nanf")
		return std::numeric_limits<double>::quiet_NaN(); //qNaN / sNaN
	if (literal == "+inf" || literal == "+inff")
		return std::numeric_limits<double>::infinity();
	if (literal == "-inf" || literal == "-inff")
		return -std::numeric_limits<double>::infinity();
	
	return 0.0;
}

void	ScalarConverter::printChar(double value)
{
	std::cout << "char: ";

	// NaN/Infinity check
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "❌ impossible" << std::endl;
		return;
	}

	// Out of ASCII range check (0-127)
	if (value < 0 || value > 127)
	{
		std::cout << "❌ impossible" << std::endl;
		return;
	}

	char c = static_cast<char>(value);

	// Is printable check
	if (!std::isprint(static_cast<unsigned char>(c))) // isprint expects (0-255) or EOF
	{
		std::cout << "Non displayable" << std::endl;
		return;
	}
	std::cout << "'" << c << "'" << std::endl;
}

void	ScalarConverter::printInt(double value)
{
	std::cout << "int: ";
	
	// NaN/Infinity check
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "❌ impossible" << std::endl;
		return;
	}

	// Overflow
	if (value < std::numeric_limits<int>::min()
	|| value > std::numeric_limits<int>::max())
	{
		std::cout << "❌ impossible" << std::endl;
		return;
	}

	std::cout << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printFloat(double value)
{
	float f = static_cast<float>(value);

	std::cout << "float: ";

	// NaN -> nanf
	if (std::isnan(f))
	{
		std::cout << "nanf" << std::endl;
		return;
	}

	// Inf -> +inff/-inff
	if (std::isinf(f))
	{
		std::cout << (f > 0 ? "+inff" : "-inff") << std::endl;
		return;
	}

	std::cout << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void	ScalarConverter::printDouble(double value)
{
	std::cout << "double: ";

	// NaN -> nanf
	if (std::isnan(value))
	{
		std::cout << "nan" << std::endl;
		return;
	}

	// Inf -> +inff/-inff
	if (std::isinf(value))
	{
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
		return;
	}

	std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}
