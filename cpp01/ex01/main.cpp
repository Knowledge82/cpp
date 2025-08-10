/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 16:10:23 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/09 19:09:15 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>

Zombie*	zombieHorde(int N, std::string name);

int	main()
{
	int	N = 5;
	std::string zombieName = "Walker";
	Zombie*	myHorde = zombieHorde(N, zombieName);
	if (!myHorde)
	{
		std::cout << "Failed to create zombie horde!" << std::endl;
		return EXIT_FAILURE;
	}

	for (int i = 0; i < N; i++)
	{
		std::cout << "#" << (i + 1) << ": ";
		myHorde[i].announce();
	}
	delete[] myHorde;
	
	return EXIT_SUCCESS;
}
