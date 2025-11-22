/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:47:22 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/26 12:37:06 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(): type("UnknownAnimal")
{
	std::cout << "🐾 Default constructor of Animal class called" << std::endl;
}

Animal::Animal(const Animal& other): type(other.type)
{	
	std::cout << "🐾 Copy constructor of Animal class called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "🐾 Assignment operator of Animal class called" << std::endl;
	if (this != &other)
	{
		type = other.type;
	}
	return *this;
}

Animal::~Animal()
{
	std::cout << "🐾 Default destructor of Animal class called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "* Generic animal sound *" <<std::endl;
}

std::string	Animal::getType() const
{
	return type;
}

