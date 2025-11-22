/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:59:25 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/24 13:54:41 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;

	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{	
	std::cout << "ScavTrap " << this->name << " constructor called" << std::endl;

	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;	
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hitPoints == 0)
	{
		std::cout << "ScavTrap " << this->name << RED" is destroyed"RESET << " and cannot attack!" << std::endl;
		return;
	}

	if (this->energyPoints == 0)
        {
                std::cout << "ScavTrap " << this->name << " has no energy to attack!" << std::endl;
                return;
        }
        this->energyPoints--;
        std::cout << "ScavTrap " << this->name << " brutally attacks " << target << ", causing devastating damage of "
                        << this->attackDamage << " points of damage" << std::endl;

}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeeper mode! 🛡️  Nobody shall pass! 🛡️"
		<< std::endl;
}

