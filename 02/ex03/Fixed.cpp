/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:46:48 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/20 14:41:53 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

//Default constructor. Fixed a
Fixed::Fixed() : rawBits_(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

//Copy constructor. Fixed b(a) | Fixed c = a
Fixed::Fixed(const Fixed& other): rawBits_(other.rawBits_)
{
	//std::cout << "Copy constructor called" << std::endl;
}

//Copy assignment operator. b = a
Fixed& Fixed::operator=(const Fixed& other)
{
	//std::cout << "Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		this->rawBits_ = other.rawBits_;
	}
	return *this;
}

//Destructor
Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

//Int constructor
Fixed::Fixed(const int intValue): rawBits_(intValue << fractionalBits_)
{
	//std::cout << "Int constructor called" << std::endl;
}

//Float constructor
Fixed::Fixed(const float floatValue): rawBits_((int)roundf(floatValue * (1 << fractionalBits_)))
{
	//std::cout << "Float consructor called" << std::endl;
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
	//std::cout << "getRawBits member function called" << std::endl;
	return this->rawBits_;
}

//Setter
void	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
	this->rawBits_ = raw;
}

//Comparation operators
bool	Fixed::operator>(const Fixed& other) const
{
	return this->rawBits_ > other.rawBits_;
}

bool	Fixed::operator<(const Fixed& other) const
{
	return this->rawBits_ < other.rawBits_;
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return this->rawBits_ >= other.rawBits_;
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return this->rawBits_ <= other.rawBits_;
}

bool	Fixed::operator==(const Fixed& other) const
{
	return this->rawBits_ == other.rawBits_;
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return this->rawBits_ != other.rawBits_;
}

//Math operators
Fixed	Fixed::operator+(const Fixed& other) const
{
	Fixed	result;
	result.rawBits_ = this->rawBits_ + other.rawBits_;
	return result;
}
Fixed	Fixed::operator-(const Fixed& other) const
{
	Fixed	result;
	result.rawBits_ = this->rawBits_ - other.rawBits_;
	return result;
}

Fixed	Fixed::operator*(const Fixed& other) const
{
	Fixed	result;
	result.rawBits_ = (this->rawBits_ * other.rawBits_) >> fractionalBits_; //a*b=a*b*256*256. делим на 256, чтобы убрать лишний масштаб(>> 8)
	return result;
}

Fixed	Fixed::operator/(const Fixed& other) const
{
	Fixed	result;
	result.rawBits_ = (this->rawBits_ << fractionalBits_) / other.rawBits_;
	return result;
}

//Inc, Dec
// epsilon = 1.0 / (1 << 8) = 1.0 / 256 = 0.00390625 - наименьшее представимое число в нашем формате(8 fractionalBits_)

//++a (inc, then return)
Fixed&	Fixed::operator++(void)
{
	this->rawBits_ += 1;
	return *this;
}

Fixed&	Fixed::operator--(void)
{
	this->rawBits_ -= 1;
	return *this;
}

//a++ (return, then inc)
Fixed	Fixed::operator++(int) // int - dummy параметр для различия, он не используется реально
{
	Fixed temp(*this); // copy current value;
	this->rawBits_ += 1; // ++
	return temp; // return OLD value
}

Fixed	Fixed::operator--(int)
{
	Fixed temp(*this);
	this->rawBits_ -= 1;
	return temp;
}

//Static funcs min/max
Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	return (a.rawBits_ < b.rawBits_) ? a : b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a.rawBits_ < b.rawBits_) ? a : b;
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	return (a.rawBits_ > b.rawBits_) ? a : b;
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a.rawBits_ > b.rawBits_) ? a : b;
}

std::ostream& operator << (std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return out;
}
