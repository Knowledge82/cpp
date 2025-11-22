/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:02:48 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/09/01 18:09:18 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	testBasic()
{
	std::cout << GREEN"\n====== BASIC TEST ======\n"RESET << std::endl;
	
	IMateriaSource* src = new MateriaSource();

	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;
	//src->learnMateria(new Ice());
	//src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	AMateria* mat = src->createMateria("ice");
	me->equip(mat);
	mat = src->createMateria("cure");
	me->equip(mat);


	me->use(0, *bob);
	me->use(1, *bob);
	std::cout << "Trying to use invalid slot ***use(42, *bob)***: ";
	me->use(42, *bob);
	std::cout << "Trying to equip NULL ***me->equip(NULL)***: ";
	me->equip(NULL);
	

	delete bob;
	delete me;
	delete src;
}

void	testCopyAndAssign()
{	
	std::cout << GREEN"\n====== COPY AND ASSIGN TEST ======\n"RESET << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;

	std::cout << "Creating new character Original" << std::endl;
	Character original("Original");

	std::cout << "Original equips ice and cure" << std::endl;
	AMateria* ice_mat = src->createMateria("ice"); //wrapper for ice for correct delete
	original.equip(ice_mat);
	AMateria* cure_mat = src->createMateria("cure");
	original.equip(cure_mat);

	std::cout << "\nCopy constructor: copy1(original)" << std::endl;
	Character copy1(original);
	std::cout << "name of copy1 - " << copy1.getName() << std::endl;

	std::cout << "\nCreating new character Copy2" << std::endl;
	Character copy2("Copy2");

	std::cout << "\nAssignment copy2 = original" << std::endl;
	copy2 = original;
	std::cout << "name of copy2 - " << copy2.getName() << std::endl;

	std::cout << "\nCreating new character Target" << std::endl;
	Character target("Target");

	std::cout << "copy1: ";
	copy1.use(0, target);
	std::cout << "copy2: ";
	copy2.use(1, target);

	std::cout << "Checking independency of the copies:" << std::endl;
	std::cout << "unequip(0) for original - ice." << std::endl;
	original.unequip(0);
	std::cout << "check (0) - ice for copy1: ";
	copy1.use(0, target);

	std::cout << "check *use* after *unequip*: use(0) for original: ";
	original.use(0, target);

	delete ice_mat; //correct ice delete
	delete src;
}

void	testInventoryLimits()
{
	std::cout << GREEN"\n====== INVENTORY LIMITS TEST ======\n"RESET << std::endl;

	IMateriaSource* src = new MateriaSource();
	
	AMateria* ice = new Ice();
	AMateria* cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	delete ice;
	delete cure;

	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");

	// try to overload inventory (more than 4 items):
       	AMateria* materias[6] = {NULL};
	for (int i = 0; i < 6; i++)
	{
		AMateria* mat = src->createMateria(i % 2 == 0 ? "ice" : "cure");
		std::cout << "Try to equip materia " << (i + 1) << std::endl;
		materias[i] = mat; // save pointer
		me->equip(mat);
	}

	for (int i = 0; i < 6; i++)
	{
		std::cout << "Using slot " << i + 1 << ": ";
		me->use(i, *bob);
	}

	// deleting 4-6 materias
	for (int i = 4; i < 6; i++)
		delete materias[i];

	delete me;
	delete bob;
	delete src;
}

void	testUnknownType()
{
	std::cout << GREEN"\n====== UNKNOWN TYPE OF MATERIA TEST ======\n"RESET << std::endl;
	IMateriaSource*	src = new MateriaSource();
	AMateria*	ice = new Ice();
	std::cout << "Learning ICE materia" << std::endl;
	src->learnMateria(ice);
	delete(ice);
	std::cout << "Trying FIRE materia..." << std::endl;
	AMateria*	tmp = src->createMateria("fire");
	if (tmp == NULL)
	std::cout << "createMateria returned NULL for unknown type" << std::endl;
	delete src;
}

int main()
{
	testBasic();
	testCopyAndAssign();
	testInventoryLimits();
	testUnknownType();

	return 0;
}
