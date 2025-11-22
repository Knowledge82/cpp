/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:03:07 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/31 18:29:40 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria(const std::string& type) : type(type)
{

}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
	
}

AMateria& AMateria::operator=(const AMateria& other)
{
	if (this != &other)
	{

	}
	return *this;
}

AMateria::~AMateria()
{

}

const std::string&	AMateria::getType() const
{
	return type;
}

void		AMateria::use(ICharacter& target)
{
	(void)target;
	// OR: std::cout << "* uses " << type << " materia *" << std::endl;
}

