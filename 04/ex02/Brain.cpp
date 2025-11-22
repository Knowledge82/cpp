/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:39:47 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/28 19:12:33 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "🧠 Brain constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = "Empty idea";
	}
}

Brain::Brain(const Brain& other)
{
	std::cout << "🧠 Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = other.ideas[i];
	}

}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "🧠 Brain assignment operator called" << std::endl;
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "🧠 Brain destructor called" << std::endl;
}

void	Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	return "";
}

void	Brain::printIdeas() const
{
	for (int i = 0; i < 5; i++)
	{
		std::cout << " Idea " << i << ": " << ideas[i] << std::endl;
	}
}

