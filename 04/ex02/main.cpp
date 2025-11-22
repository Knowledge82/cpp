/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 18:46:13 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/30 18:09:05 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

#include <iostream>

void	testCreateAndDelete()
{
	std::cout << GREEN"\n===== TEST OF CREATION AND DELETION ====="RESET << std::endl;

	std::cout << GREEN"\nCreating Dog through Animal pointer:"RESET << std::endl;
	const Animal* j = new Dog();

	std::cout << GREEN"\nCreating Cat through Animal pointer:"RESET << std::endl;
	const Animal* i = new Cat();

	std::cout << GREEN"\nTesting polymorphism:"RESET << std::endl;
	std::cout << "Dog->makeSound(): ";
	j->makeSound();
	std::cout << "Cat->makeSound(): ";
	i->makeSound();

	std::cout << GREEN"\nDeleting through Animal pointers(testing virtual destructors):"RESET << std::endl;
	delete j;
	std::cout << std::endl;
	delete i;
}

void	testDeepCopy()
{
	std::cout << GREEN"\n===== DEEP COPY TEST ====="RESET << std::endl;

	std::cout << GREEN"\nCreating original dog:"RESET << std::endl;
	Dog	originalDog;

	std::cout << GREEN"\nOriginal dog's ideas:"RESET << std::endl;
	originalDog.getBrain()->printIdeas();

	std::cout << GREEN"\nCopying dog (deep copy test):"RESET << std::endl;
	Dog	copiedDog(originalDog);

	std::cout << GREEN"\nCopyied dog's ideas:"RESET << std::endl;
	copiedDog.getBrain()->printIdeas();

	std::cout << "\nModifying original dog's brain...(setting new idea)" << std::endl;
	originalDog.getBrain()->setIdea(0, "NEW IDEA: Eat everything!");

	std::cout << GREEN"\nAfter modification:"RESET << std::endl;
	std::cout << "Original dog idea 0: " << originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied dog idea 0: " << copiedDog.getBrain()->getIdea(0) << std::endl;

	std::cout << "Analyzing DEEP COPY: ";
	if (originalDog.getBrain()->getIdea(0) != copiedDog.getBrain()->getIdea(0))
		std::cout << "✅ DEEP COPY SUCCESS. Objects have independent brains!" << std::endl;
	else
		std::cout << "❌ SHALLOW COPY DETECTED. Objects share the same brain!" << std::endl;
	
	std::cout << std::endl;
}

void	testArrayOfAnimals()
{
	std::cout << GREEN"\n===== ARRAY OF ANIMALS TEST =====\n"RESET << std::endl;

	const int	arraySize = 6;
	Animal*		animals[arraySize];

	std::cout << "Creating array of animals:" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
		{
			std::cout << "Creating Dog " << i << ":" << std::endl;
			animals[i] = new Dog();
		}
		else
		{
			std::cout << "Creating Cat " << i << ":" << std::endl;
			animals[i] = new Cat();
		}
		std::cout << std::endl;
	}

	std::cout << "Making all animals sound:" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Animal " << i << " (" << animals[i]->getType() << "): " << std::endl;
		animals[i]->makeSound();
	}
	
	std::cout << "\nDeleting all animals:" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << "Deleting animal " << i << " (" << animals[i]->getType() << "): " << std::endl;
		delete animals[i];
	}
}

void	testShallowAndDeepCopyDemonstration()
{
	std::cout << GREEN"\n===== SHALLOW AND DEEP COPY TEST =====\n"RESET << std::endl;
	
	std::cout << "Creating dog1:" << std::endl;
	Dog*	dog1 = new Dog();
	std::cout << "\nCreating copy of dog1:" << std::endl;
	Dog*	dog2 = new Dog(*dog1);

	std::cout << GREEN"\nBrain addresses:"RESET << std::endl;
	std::cout << "dog1 brain address: " << dog1->getBrain() << std::endl;
	std::cout << "dog2 brain address: " << dog2->getBrain() << std::endl;

	if (dog1->getBrain() != dog2->getBrain())
		std::cout << "✅ DIFFERENT ADDRESSES: Deep copy confirmed!" << std::endl;
	else
		std::cout << "❌ SAME ADDRESSES: Shallow copy detected!" << std::endl;
	
	std::cout << "\nDeleting dog1..." << std::endl;
	delete dog1;
	std::cout << "\nAfter deleting dog1, dog2 is still valid:" << std::endl;
	dog2->makeSound();

	std::cout << "\nDeleting dog2..." << std::endl;
	delete dog2;
}

void	testStackObjects()
{
	std::cout << GREEN"\n===== STACK OBJECTS TEST =====\n"RESET << std::endl;

	std::cout << "Creating stack objects:" << std::endl;
	Dog	stackDog1;
	Dog	stackDog2(stackDog1);

	std::cout << "Stack objects will be automatically destroyed..." << std::endl;
}

int	main()
{
	testCreateAndDelete();
	testDeepCopy();
	testArrayOfAnimals();
	testShallowAndDeepCopyDemonstration();
	testStackObjects();
	
	std::cout << GREEN"\n===== END OF ALL TESTS =====\n"RESET << std::endl;

	return 0;
}
