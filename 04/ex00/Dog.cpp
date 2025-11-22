/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:46:46 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/25 17:20:38 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	std::cout << "🐕 Dog default constructor called"  << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
	std::cout << "🐕 Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{	
	std::cout << "🐕 Dog assignment operator called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog()
{
	std::cout << "🐕 Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
