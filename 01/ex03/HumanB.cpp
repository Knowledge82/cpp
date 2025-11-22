/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:14:24 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/10 11:14:27 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(NULL)
{
	std::cout << "HumanB " << this->name << " created (no weapon)" << std::endl;
}

HumanB::~HumanB()
{
	std::cout << "HumanB " << this->name << " destroyed" << std::endl;
}

void	HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
	std::cout << this->name << " is now armed with " << weapon.getType() << std::endl;
}

void	HumanB::attack() const
{
	if (this->weapon)
	{
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	}
	else
	{
		std::cout << this->name << " attacks with their hands (no weapon)!" << std::endl;	
	}
}
