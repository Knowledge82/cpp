/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:10:00 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/10 11:08:54 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int	main()
{
	std::cout << "======== Testing HumanA (reference - always armed)" <<std::endl;
	{
		Weapon axe = Weapon("two handed axe");
		HumanA maxim("Maxim", axe);
		
		maxim.attack();

		axe.setType("another random axe");
		maxim.attack(); //изменение оружия отразится на HumanA через ссылку
	}
	
	std::cout << "======== Testing HumanB (pointer - may be unarmed)" <<std::endl;
	{
		Weapon axe = Weapon("two handed axe");
		HumanB pavel("Pavel");

		pavel.attack(); //без оружия
		pavel.setWeapon(axe);
		pavel.attack(); //с оружием

		axe.setType("another random axe");
		pavel.attack(); //изменение оружия отразится на HumanB через указатель
	}

	std::cout << "\n====== Additional tests =======" << std::endl;
	{
		Weapon sword("one handed silver sword");
		Weapon bow("elvish bow");

		//HumanA всегда вооружен с момента создания
		HumanA warrior("Aragorn", sword);
		warrior.attack();

		//HumanB может менять оружие или быть безоружным
		HumanB archer("Legolas");
		archer.attack();//без оружия
		archer.setWeapon(bow);
		archer.attack();//лук
		archer.setWeapon(sword);
		archer.attack();//меч
	}
	return 0;
}
