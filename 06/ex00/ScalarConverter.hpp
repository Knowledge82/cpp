/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:23:11 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/01 16:45:17 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

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

	static void	convert(const std::string& input);
	static void	parseToDouble(const std::string& input, LitType type);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static LitType	detectType(const std::string& input);
	static bool	isPseudo(const std::string& literal);
	static bool	isChar(const std::string& literal);
	static bool	isInt(const std::string& literal);
	static bool	isFloat(const std::string& literal);
	static bool	isDouble(const std::string& literal);
};

#endif
