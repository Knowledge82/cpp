/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 09:07:38 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/24 14:02:00 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "DiamondTrap.hpp"

void	main_test()
{
	std::cout << GREEN"\n====== Testing DiamondTrap ======"RESET << std::endl;
	
	DiamondTrap	diamond("Diamond");
	
	diamond.whoAmI();
	std::cout << "Methods:" << std::endl;	
	diamond.attack("The Supreme Ultimate Boss");
	diamond.guardGate();
	diamond.highFivesGuys();
	
	std::cout << GREEN"\n====== Testing copy and assignment ======"RESET << std::endl;
	std::cout << "\nCopy:" << std::endl;
	DiamondTrap	diamond2(diamond);
	std::cout << "\nCreate and assignment:";
	DiamondTrap	diamond3;
	diamond3 = diamond;
	
	std::cout << GREEN"\n====== End of testing ======"RESET << std::endl;
}

int	main(void)
{
	main_test();

	return 0;
}
