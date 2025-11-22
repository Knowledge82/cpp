/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:46:48 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/19 14:03:24 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//Default constructor. Fixed a
Fixed::Fixed() : rawBits_(0)
{
	std::cout << "Default constructor called" << std::endl;
}

//Copy constructor. Fixed b(a) | Fixed c = a
Fixed::Fixed(const Fixed& other): rawBits_(other.rawBits_)
{
	std::cout << "Copy constructor called" << std::endl;
}

//Copy assignment operator. b = a
Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		this->rawBits_ = other.rawBits_;
	}
	return *this;
}

//Destructor
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//Int constructor
Fixed::Fixed(const int intValue): rawBits_(intValue << fractionalBits_)
{
	std::cout << "Int constructor called" << std::endl;
}

//Float constructor
Fixed::Fixed(const float floatValue): rawBits_((int)roundf(floatValue * (1 << fractionalBits_)))
{
	std::cout << "Float consructor called" << std::endl;
}

//Convertion to int
int	Fixed::toInt(void) const
{
	return rawBits_ >> fractionalBits_;
}

//Convertion to float
float	Fixed::toFloat(void) const
{
	return (float)rawBits_ / (1 << fractionalBits_);
}

//Getter
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits_;
}

//Setter
void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->rawBits_ = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
