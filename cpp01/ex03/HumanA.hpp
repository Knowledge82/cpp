/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:11:33 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/10 10:18:05 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <string>

class	HumanA
{
private:
	std::string	name;
	Weapon&		weapon; // ссылка - значит всегда имеет оружие
	
public:
	HumanA(const std::string& name, Weapon& weapon);
	~HumanA();

	void	attack() const;
};

#endif
