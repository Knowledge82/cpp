/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:46:48 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/19 13:08:44 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

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
