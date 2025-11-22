/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:03:04 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/28 14:56:04 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
//	arr = new int[100];
	std::cout << "❌🐱 WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other)
{
	std::cout << "❌🐱 WrongCat copy constructor called" << std::endl;	
}

WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "❌🐱 WrongCat assignment operator called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat()
{
//	delete[] arr;
	std::cout << "❌🐱 WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong Meow! Wrong Meow!" << std::endl;
}

std::string	WrongCat::getType() const
{
	return type;
}
