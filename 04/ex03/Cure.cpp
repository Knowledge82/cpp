/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:03:51 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/31 18:31:03 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(const Cure& other) : AMateria("cure")
{
	(void)other;
}

Cure& Cure::operator=(const Cure& other)
{
	if (this != &other)
	{
	//	AMateria::operator=(other);
	}
	return *this;
}

Cure::~Cure()
{

}

AMateria*	Cure::clone() const
{
	return new Cure(*this);
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

