/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:07:53 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/23 13:39:34 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#define GREEN	"\033[0;32m"
#define RED	"\033[0;31m"
#define RESET	"\033[0m"

#include <iostream>
#include <string>

class	ClapTrap
{
protected:
	std::string	name;
	unsigned int	hitPoints;
	unsigned int	energyPoints;
	unsigned int	attackDamage;

public:
	ClapTrap();
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	// Getters
	std::string     getName() const;
	unsigned int    getHitPoints() const;
	unsigned int    getEnergyPoints() const;
	unsigned int    getAttackDamage() const;

};

#endif
