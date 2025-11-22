/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:46:54 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/28 19:07:32 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat() : brain(new Brain())
{
	type = "Cat";
	std::cout << "🐱 Cat default constructor called" << std::endl;

	brain->setIdea(0, "Sleep all day");
	brain->setIdea(1, "Ignore humans");
	brain->setIdea(2, "Random cat's idea");
	brain->setIdea(3, "Another random cat's idea");
}

Cat::Cat(const Cat& other) : Animal(other), brain(new Brain(*other.brain)) // <--- deep copy
{
	std::cout << "🐱 Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
	std::cout << "🐱 Cat assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other); // copy base part
		*brain = *other.brain;	// deep copy brain part
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "🐱 Cat destructor called" << std::endl;
	delete brain; // free memory
}

void	Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}

Brain*	Cat::getBrain() const
{
	return brain;
}
