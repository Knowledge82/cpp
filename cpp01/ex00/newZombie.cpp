/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:41:25 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/09 14:33:09 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// HEAP zombie
Zombie*	newZombie(std::string name)
{
	Zombie*	z = new Zombie(name);
	return z;
}
