/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:23:11 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/02 11:35:30 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class	ScalarConverter
{
public:
	enum	LitType
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDO,
		INVALID
	};

	static void	convert(const std::string& literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static LitType	detectType(const std::string& literal);
	static bool	isPseudo(const std::string& literal);
	static bool	isChar(const std::string& literal);
	static bool	isInt(const std::string& literal);
	static bool	isFloat(const std::string& literal);
	static bool	isDouble(const std::string& literal);
	
	static double	parseToDouble(const std::string& literal, LitType type);
	static double	parsePseudo(const std::string& literal);

	static void	printChar(double value);
	static void	printInt(double value);
	static void	printFloat(double value);
	static void	printDouble(double value);
};

#endif
