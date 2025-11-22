/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:46:39 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/19 14:22:32 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
private:
	int			rawBits_;
	static const int	fractionalBits_ = 8;
	// value = rawBits_ / 256
	
public:
	//Orthodox Canonical Form
	
	Fixed(); //Default constructor
	Fixed(const Fixed& other); //Copy constructor
	Fixed& operator=(const Fixed& other); // Copy assigment operator
	~Fixed(); //Destructor

	Fixed(const int intValue); // int constructor
	Fixed(const float floatValue); // float constructor

	//Convertation methods
	int	toInt(void) const;
	float	toFloat(void) const;

	//Getters
	int	getRawBits(void) const;

	//Setters
	void	setRawBits(int const raw);

	//Comparation operators
	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	//Math operators
	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	//Increment / decrement operators
	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	//Static funcs min/max
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator << (std::ostream& out, const Fixed& fixed);

#endif
