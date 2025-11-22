/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:46:13 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/30 13:26:50 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

void	testGoodPolymorphism()
{
	std::cout << GREEN"\n===== TEST GOOD POLYMORPHISM =====\n"RESET << std::endl;

	std::cout << GREEN"\nCreation:"RESET << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << GREEN"\nTypes:"RESET << std::endl;
	std::cout << "meta->getType(): " << meta->getType() << std::endl;
	std::cout << "j->getType(): " << j->getType() << std::endl;
	std::cout << "i->getType(): " << i->getType() << std::endl;
	
	std::cout << GREEN"\nSounds:"RESET << std::endl;
	meta->makeSound();
	j->makeSound();
	i->makeSound();

	std::cout << GREEN"\nCleans:"RESET << std::endl;
	delete meta;
	delete j;
	delete i;

	std::cout << GREEN"\n===== END OF GOOD TESTS ====="RESET << std::endl;
}

void	testWrongPolymorphism()
{
	std::cout << GREEN"\n===== ❌TEST WRONG POLYMORPHISM =====\n"RESET << std::endl;

	std::cout << GREEN"\n❌Creation:"RESET << std::endl;
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongCat* wrongCat = new WrongCat();
	const WrongAnimal* eternalCat = new WrongCat();

	std::cout << GREEN"\n❌Types:"RESET << std::endl;
	std::cout << "wrongMeta->getType(): " << wrongMeta->getType() << std::endl;
	std::cout << "wrongCat->getType(): " << wrongCat->getType() << std::endl;
	std::cout << "eternalCat->getType(): " << eternalCat->getType() << std::endl;
		
	std::cout << GREEN"\n❌Sounds:"RESET << std::endl;
	wrongMeta->makeSound();
	wrongCat->makeSound();
	eternalCat->makeSound();
	
	std::cout << GREEN"\n❌Cleans:"RESET << std::endl;
	delete wrongMeta;
	delete wrongCat;
	delete eternalCat;

	std::cout << GREEN"\n===== ❌END OF WRONG TESTS ====="RESET << std::endl;
}

int	main()
{
	testGoodPolymorphism();
	testWrongPolymorphism();

	return 0;
}
