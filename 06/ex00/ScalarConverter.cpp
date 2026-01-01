/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 17:01:35 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/01 17:53:22 by vdarsuye         ###   ########.fr       */
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

/* Когда try/catch уместен:
* - Работа с памятью (new может бросить bad_alloc)
* - Файловые операции
* - Критические ошибки
* Для парсинга строки - однозначно if/else! */
LitType	detectType(const std::string& lit)
{
	if (isPseudo(lit))
		return PSEUDO;
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

bool	ScalarConverter::isChar(const std::string& lit)
{
	return (lit.length() == 3 && lit[0] == '\'' && lit[2] == '\'')
}

bool	ScalarConverter::isInt(const std::string& lit)
{
	if (lit.empty())
		return false;

	char	*end;
	std::strtol(lit.c_str(), &end, 10);

	return (*end == '\0');
}

bool	ScalarConverter::isFloat(const std::string& lit)
{
	if (lit.empty() || lit[lit.length() - 1] != 'f')
		return false;

	std::string numPart = lit.substr(0, lit.length() - 1); // cut 'f'
	if (numPart.empty() || numPart.find('.') == std::string::npos)
		return false;

	char	*end;
	sd::strtod(numPart.c_str(), &end);

	return (*end == '\0');
}

bool	ScalarConverter::isDouble(const std::string& lit)
{
	if (lit.empty())
		return false;

	if (lit.find('.') == std::string::npos)
		return false;

	char	*end;
	std::strtod(lit.c_str(), &end);

	return (*end == '\0');
}

bool	ScalarConverter::isPseudo(const std::string& lit)
{
	return (lit == "nanf" || lit == "+inff" || lit == "-inff" ||
		lit == "nan"  || lit == "+inf"  || lit == "-inf");
}

void	ScalarConverter::convert(const std::string& input)
{
	LitType type = detectType(input);

	if (type == INVALID)
	{
		std::cout << "Error: invalid literal" << std::endl;
		return;
	}

	double value = parseToDouble(input, type);

	printChar(value, type);
	printInt(value, type);
	printFloat(value, type);
	printDouble(value, type);
}

// parse any value in double coz it's a most widest type
void	ScalarConverter::parseToDouble(const std::string& input, LitType type)
{
	switch (type)
	{
		case CHAR:
			return static_cast<double>(input[1]);

		case INT:
			return std::strtod(input.c_str(), NULL);

		case FLOAT:
		{
			std::string numPart = input.substr(0, input.length() - 1);
			return std::strtod(numPart.c_str(), NULL);
		}

		case DOUBLE:
			return std::strtod(input.c_str(), NULL);

		case PSEUDO:
			return parsePseudo(input);

		default:
			return 0.0;
	}
}

double	ScalarConverter::parsePseudo(const std::string& input)
{
	if (input == "nan" || input == "nanf")
		return std::numeric_limits<double>::quiet_NaN(); //qNaN / sNaN
	if (input == "+inf" || input == "+inff")
		return std::numeric_limits<double>::infinity();
	if (input == "-inf" || input == "-inff")
		return -std::numeric_limits<double>::infinity();
	
	return 0.0;
}

void	ScalarConverter::printChar(double value, LitType type)
{
	std::cout << "char: ";

	// NaN/Infinity check
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std:endl;
		return;
	}

	// Out of ASCII range check (0-127)
	if (value < 0 || value > 127)
	{
		std::cout << "impossible" << std:endl;
		return;
	}

	char c = static_cast<char>(value);

	// Is printable check
	if (!std::isprint(static_cast<unsigned char>(c))) // isprint expects (0-255) or EOF
	{
		std::cout << "Non displayable" << std:endl;
		return;
	}
	std::cout << "'" << c << "'" << std::endl;
}

void	ScalarConverter::printInt(double value, LitType type)
{
	std::cout << "int: ";
	
	// NaN/Infinity check
	if (std::isnan(value) || std::isinf(value))
	{
		std::cout << "impossible" << std:endl;
		return;
	}

	// Overflow
	if (value < std::numeric_limits<int>::min()
	|| value > std::numeric_limits<int>::max())
	{
		std::cout << "impossible" << std:endl;
		return;
	}

	std::cout << static_cast<int>(value) << std::endl;
}

void	ScalarConverter::printFloat(double value, LitType type)
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

void	ScalarConverter::printDouble(double value, LitType type)
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
