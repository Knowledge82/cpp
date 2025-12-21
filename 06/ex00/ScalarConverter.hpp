/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 16:23:11 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/21 17:03:21 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

class	ScalarConverter
{
public:
	static void	convert(const std::string& literal);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static const std::string&	detectType(const std::string& input);
	static bool			isChar(const std::string& literal);
	static bool			isInt(const std::string& literal);
	static bool			isFloat(const std::string& literal);
	static bool			isDouble(const std::string& literal);
	static bool			isPseudoLiteral(const std::string& literal);
};

#endif
