/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:07:38 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/23 11:08:49 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScavTrap.hpp"

void	main_test()
{
	std::cout << GREEN"\n====== Testing ClapTrap ======"RESET << std::endl;
	ClapTrap	clap("Clappy");

	std::cout << GREEN"\n====== Testing ScavTrap and ClapTrap attacks ======"RESET << std::endl;
	ScavTrap	scav("Scavvy");
	clap.attack("common target");
	scav.attack("elite enemy");

	std::cout << GREEN"\n====== Testing copy and assignment ======"RESET << std::endl;
	std::cout << "\nCopy:" << std::endl;
	ScavTrap	scav2(scav);
	std::cout << "Create and assignment:" << std::endl;
	ScavTrap	scav3;
	scav3 = scav;

	std::cout << GREEN"\n====== End of testing ======"RESET << std::endl;
}

int	main(void)
{
	main_test();

	return 0;
}
