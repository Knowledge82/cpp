/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:12:41 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/10 10:18:52 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>

class	HumanB
{
private:
	std::string	name;
	Weapon*		weapon; // указатель - может быть NULL, значит может не имеет оружия

public:
	HumanB(const std::string& name);
	~HumanB();

	void	setWeapon(Weapon& weapon);
	void	attack() const;
};

#endif
