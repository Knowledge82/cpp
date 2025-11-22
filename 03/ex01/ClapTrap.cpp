/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:07:59 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/23 13:43:24 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("Default"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "\nClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << "\nClapTrap constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): name(other.name), hitPoints(other.hitPoints), energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
	std::cout << "ClapTrap copy constructor called for " << name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap assignmnent operator called" << std::endl;

	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\nClapTrap destructor called for " << name << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << RED" is destroyed"RESET << " and cannot attack!" << std::endl;
		return;
	}
	
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy to attack!" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
			<< attackDamage << " points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already " << RED"destroyed!"RESET << std::endl;
		return;
	}
	// Calculating DMG. HP cannot be negative
	if (amount >= hitPoints)
	{
		std::cout << "ClapTrap " << name << " takes " << hitPoints 
			<< " points of damage and is " << RED"destroyed."RESET << std::endl;
		hitPoints = 0;
	}
	else
	{
		hitPoints -= amount;
		std::cout << "ClapTrap " << name << " takes " << amount
			<< " points of damage. Health remaining: " << hitPoints << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints == 0)
	{
		std::cout << "ClapTrap " << name << " is already " << RED"destroyed"RESET << " and cannot be repaired!" << std::endl;
		return;
	}
	
	if (energyPoints == 0)
	{
		std::cout << "ClapTrap " << name << " has no energy to repair!" << std::endl;
		return;
	}
	energyPoints--;
	hitPoints += amount;
	std::cout << "ClapTrap " << name << " repairs itself for " << amount
		<< " points of health. Actual health: " << hitPoints << std::endl;
}

// Getters
std::string	ClapTrap::getName() const
{
	return name;
}

unsigned int	ClapTrap::getHitPoints() const
{
	return hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return energyPoints;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return attackDamage;
}
