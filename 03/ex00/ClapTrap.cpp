/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:07:59 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/21 14:34:42 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(): name_("Unnamed"), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
	std::cout << "\nClapTrap default constructor called for " << name_ << std::endl;
}

ClapTrap::ClapTrap(const std::string& name): name_(name), hitPoints_(10), energyPoints_(10), attackDamage_(0)
{
	std::cout << "\nClapTrap constructor called for " << name_ << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): name_(other.name_), hitPoints_(other.hitPoints_), energyPoints_(other.energyPoints_), attackDamage_(other.attackDamage_)
{
	std::cout << "ClapTrap copy constructor called for " << name_ << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap assignmnent operator called" << std::endl;

	if (this != &other)
	{
		name_ = other.name_;
		hitPoints_ = other.hitPoints_;
		energyPoints_ = other.energyPoints_;
		attackDamage_ = other.attackDamage_;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "\nClapTrap destructor called for " << name_ << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (hitPoints_ == 0)
	{
		std::cout << "ClapTrap " << name_ << RED" is destroyed"RESET << " and cannot attack!" << std::endl;
		return;
	}
	
	if (energyPoints_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " has no energy to attack!" << std::endl;
		return;
	}
	energyPoints_--;
	std::cout << "ClapTrap " << name_ << " attacks " << target << ", causing "
			<< attackDamage_ << " points of damage" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " is already " << RED"destroyed!"RESET << std::endl;
		return;
	}
	// Calculating DMG. HP cannot be negative
	if (amount >= hitPoints_)
	{
		std::cout << "ClapTrap " << name_ << " takes " << hitPoints_ 
			<< " points of damage and is " << RED"destroyed."RESET << std::endl;
		hitPoints_ = 0;
	}
	else
	{
		hitPoints_ -= amount;
		std::cout << "ClapTrap " << name_ << " takes " << amount
			<< " points of damage. Health remaining: " << hitPoints_<< std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " is already " << RED"destroyed"RESET << " and cannot be repaired!" << std::endl;
		return;
	}
	
	if (energyPoints_ == 0)
	{
		std::cout << "ClapTrap " << name_ << " has no energy to repair!" << std::endl;
		return;
	}
	energyPoints_--;
	hitPoints_ += amount;
	std::cout << "ClapTrap " << name_ << " repairs itself for " << amount
		<< " points of health. Actual health: " << hitPoints_<< std::endl;
}

// Getters
std::string	ClapTrap::getName() const
{
	return name_;
}

unsigned int	ClapTrap::getHitPoints() const
{
	return hitPoints_;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return energyPoints_;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return attackDamage_;
}

