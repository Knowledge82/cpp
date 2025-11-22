/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:43:53 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/24 14:01:07 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("DefaultDiamond"), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;

	this->name = "DefaultDiamond";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	std::cout << "DiamondTrap constructor called for" << name << std::endl;
	
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other)
	: ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	
	name = other.name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
	std::cout << "DiamondTrap assignment operator called" << std::endl;

	if (this != &other)
	{
		ClapTrap::operator=(other);
		this->name = other.name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called for " << name << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << GREEN"\nWHO AM I:"RESET << std::endl;
	std::cout << "DiamondTrap name: " << this->name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;	
	std::cout << "Hit Points: " << this->hitPoints << std::endl;
	std::cout << "Energy Points: " << this->energyPoints << std::endl;
	std::cout << "Attack Damage: " << this->attackDamage << std::endl;
}

