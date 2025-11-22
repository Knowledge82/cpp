/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:40:29 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/09 14:40:48 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie* heapZombie = newZombie("HEAP-zombie");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "========================" << std::endl;

	randomChump("STACK-zombie");

	return 0;
}
