/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:10:23 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/09 20:25:53 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class	Weapon
{
private:
	std::string	type;

public:
	Weapon();
	Weapon(const std::string& type);
	~Weapon();

	//Setters
	void	setType(const std::string& newType);
	
	// Getters
	const std::string&	getType() const;
};

#endif
