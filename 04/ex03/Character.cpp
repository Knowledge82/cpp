/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:53:37 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/09/01 18:02:43 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character(const std::string& name) : name(name)
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& other) : name(other.name)
{
	// NULLing inventory, good practice
	for (int i = 0; i < INVENTORY_SIZE; i++)
		inventory[i] = NULL;
	
	// deep copy
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (other.inventory[i] != NULL)
			inventory[i] = other.inventory[i]->clone();
	}
}

Character& Character::operator=(const Character& other)
{
	if (this != &other)
	{
		// del old materias
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			delete inventory[i];
			inventory[i] = NULL;
		}
		// copy name
		name = other.name;
		//clone new materias
		for (int i = 0; i < INVENTORY_SIZE; i++)
		{
			if (other.inventory[i] != NULL)
				inventory[i] = other.inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		delete inventory[i];
		inventory[i] = NULL;
	}
}

const std::string&	Character::getName() const
{
	return name;
}

void	Character::equip(AMateria* m)
{
	if (m == NULL)
	{
		std::cerr << RED"Error: you can't equip NULL."RESET << std::endl;
		return;
	}
	for (int i = 0; i < INVENTORY_SIZE; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return;
		}
	}
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= INVENTORY_SIZE)
	{
		std::cerr << RED"Invalid inventory slot"RESET << std::endl;
		return;
	}
	if (inventory[idx] != NULL)
		inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= INVENTORY_SIZE || inventory[idx] == NULL)
	{
		std::cerr << RED"Invalid inventory slot"RESET << std::endl;
		return;
	}
	if (inventory[idx] != NULL)
		inventory[idx]->use(target);
}
