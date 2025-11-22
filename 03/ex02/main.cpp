/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:07:38 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/23 11:11:25 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void	main_test()
{
	std::cout << GREEN"\n====== Testing ClapTrap ======"RESET << std::endl;
	ClapTrap	clap("Clappy");
	clap.attack("common target");
	clap.takeDamage(5);
	clap.beRepaired(3);

	std::cout << GREEN"\n====== Testing ScavTrap ======"RESET << std::endl;
	ScavTrap	scav("Scavvy");
	scav.attack("elite enemy");
	scav.guardGate();
	
	std::cout << GREEN"\n====== Testing FragTrap ======"RESET << std::endl;
	FragTrap	frag("Fraggy");
	frag.attack("boss");
	frag.highFivesGuys();
	frag.takeDamage(50);
	frag.beRepaired(20);
	
	std::cout << GREEN"\n====== Testing copy and assignment ======"RESET << std::endl;
	std::cout << "Copy:" << std::endl;
	FragTrap	frag2(frag);
	std::cout << "Create and assignment:" << std::endl;
	FragTrap	frag3;
	frag3 = frag;
	
	std::cout << GREEN"\n====== End of testing ======"RESET << std::endl;
}

int	main(void)
{
	main_test();

	return 0;
}
