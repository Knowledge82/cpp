/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 11:13:19 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/31 18:30:40 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice")
{

}

Ice::Ice(const Ice& other) : AMateria("ice")
{
	(void)other;	
}

Ice& Ice::operator=(const Ice& other)
{
	if (this != &other)
	{
	//	AMateria::operator=(other);
	}
	return *this;
}

Ice::~Ice()
{

}

AMateria*	Ice::clone() const
{
	return new Ice(*this); // pattern Prototype (self copy)
}

void	Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

