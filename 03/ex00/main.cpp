/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:07:38 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/23 11:13:54 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"

void	main_test()
{
	std::cout << GREEN"\n====== Basic test ======"RESET << std::endl;

	ClapTrap	robot("T800");

	// Init
	std::cout << GREEN"\nInitiating..."RESET << std::endl;
	std::cout << "Name: " << robot.getName() << std::endl;
	std::cout << "Health: " << robot.getHitPoints() << std::endl;
	std::cout << "Energy: " << robot.getEnergyPoints() << std::endl;
	std::cout << "Attack power: " << robot.getAttackDamage() << std::endl;

	// Attack
	std::cout << GREEN"\nAttack test"RESET << std::endl;
	robot.attack("Enemy");
	robot.attack("Another enemy");

	// Get damage
	std::cout << GREEN"\nDamage test"RESET << std::endl;
	robot.takeDamage(3);
	robot.takeDamage(5);

	// Repair
	std::cout << GREEN"\nRepair test"RESET << std::endl;
	robot.beRepaired(2);
	robot.beRepaired(1);

	std::cout << GREEN"\nActual stats:"RESET << std::endl;
	std::cout << "HP: " << robot.getHitPoints() << std::endl;
	std::cout << "Energy: " << robot.getEnergyPoints() << std::endl;
	
	std::cout << GREEN"\n====== End of main test ======"RESET << std::endl;
}

void	test_edge_cases()
{
	std::cout << GREEN"\n====== Edge cases test ======="RESET << std::endl;

	// Energy case
	ClapTrap	energyBot("Tesla Atlas");

	std::cout << "\nWasting energy..." << std::endl;
	for(int i = 0; i < 12; i++)
	{
		std::cout << "action " << (i + 1) << ": ";
		if (i % 2 == 0)
			energyBot.attack("Target");
		else
			energyBot.beRepaired(1);
	}

	// Death case

	ClapTrap	deathBot("Figure 02");
	
	std::cout << "\n";
	deathBot.takeDamage(69);	
	deathBot.attack("Random Human Target");	
	deathBot.beRepaired(69);	
	deathBot.takeDamage(666);

	std::cout << GREEN"\n====== End of edge cases test ======"RESET << std::endl;
}

int	main()
{
	main_test();
	test_edge_cases();

	std::cout << GREEN"\n====== End of program ======"RESET << std::endl;
	return 0;
}
