/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:46:46 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/30 15:30:33 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain())
{
	type = "Dog";
	std::cout << "🐕 Dog default constructor called"  << std::endl;

	brain->setIdea(0, "Chase cats");
	brain->setIdea(1, "Protect the house");
	brain->setIdea(2, "Random dog's idea");
	brain->setIdea(3, "Another dog's idea");
}

Dog::Dog(const Dog& other): Animal(other), brain(new Brain(*other.brain)) //<--- deep copy
{
	std::cout << "🐕 Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{	
	std::cout << "🐕 Dog assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other); // copy base "animal" part
		*brain = *other.brain;   // deep copy brain part
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "🐕 Dog destructor called" << std::endl;
	delete brain; // free memory
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}

Brain*	Dog::getBrain() const
{
	return brain;
}
