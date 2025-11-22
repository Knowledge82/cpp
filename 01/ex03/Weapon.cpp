/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:11:03 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/10 10:16:49 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon() : type("hands(no weapon)")
{
	std::cout << "Weapon created (default: " << this->type << ")" << std::endl;
}

Weapon::Weapon(const std::string& type) : type(type)
{
	std::cout << "Weapon created " << this->type << std::endl;
}

Weapon::~Weapon()
{
	std::cout << "Weapon " << this->type << " destroyed" << std::endl;
}

void	Weapon::setType(const std::string& newType)
{
	std::cout << "Weapon type changed from " << this->type << " to " << newType << std::endl;
	this->type = newType;
}

const std::string&	Weapon::getType() const
{
	return (this->type);
}
