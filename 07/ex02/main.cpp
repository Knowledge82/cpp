/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 11:19:36 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/19 12:52:42 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Colors.hpp"
#include "Array.hpp"

int	main()
{
	std::cout << std::endl;
	std::cout << GREEN"============== Tests ==============="RESET << std::endl;

	std::cout << NEON_GREEN"\nCreating empty array (default constructor):"RESET << std::endl;
	Array<int> empty;
	std::cout << "Size of array: " << empty.size() << std::endl;
	std::cout << GREEN"---------------------------------------------"RESET << std::endl;
	
	std::cout << NEON_GREEN"\nCreating array with size of n:"RESET << std::endl;
	Array<int> arr(5);
	std::cout << "Size of array: " << arr.size() << std::endl;
	std::cout << "Checking initialization of array's elements (Should be 0)"<< std::endl;
	std::cout << "arr: "<< arr << std::endl;
	std::cout << GREEN"---------------------------------------------"RESET << std::endl;
	
	std::cout << NEON_GREEN"\nModifying array (index * 10):"RESET << std::endl;
	for (unsigned int i = 0; i < arr.size(); i++)
		arr[i] = i * 10;

	std::cout << "Modified arr: " << arr << std::endl;
	std::cout << GREEN"---------------------------------------------"RESET << std::endl;

	std::cout << NEON_GREEN"\nDeep copy test:"RESET << std::endl;
	std::cout << "Creating original array... " << std::endl;
	Array<int> original(3);
	original[0] = 7;
	original[1] = 7;
	original[2] = 7;
	std::cout << "Size of array: " << original.size() << std::endl;
	std::cout << "original array: " << original << std::endl;
	
	std::cout << "\nCreating copy array (deep copy)... " << std::endl;
	Array<int> copy(original);
	std::cout << "Size of array: " << copy.size() << std::endl;
	std::cout << "copy array: " << copy << std::endl;
	
	std::cout << "\nModifying copy array (copy[1] = 666)... " << std::endl;
	copy[1] = 666;
	
	std::cout << "original array: " << original << std::endl;
	std::cout << "copy array: " << copy << std::endl;
	std::cout << GREEN"---------------------------------------------"RESET << std::endl;

	std::cout << NEON_GREEN"\nAssignment test:"RESET << std::endl;
	std::cout << "Creating arr1... " << std::endl;
	Array<int> arr1(3);
	arr1[0] = 1;
	arr1[1] = 2;
	arr1[2] = 3;
	std::cout << "Size of array: " << arr1.size() << std::endl;
	std::cout << "arr1: " << arr1 << std::endl;
	std::cout << std::endl;

	std::cout << "Creating arr2... " << std::endl;
	Array<int> arr2(5);
	std::cout << "Size of array: " << arr2.size() << std::endl;
	std::cout << "arr2: " << arr2 << std::endl;
	std::cout << std::endl;

	std::cout << "Assignment arr2 = arr1... " << std::endl;
	arr2 = arr1;
	std::cout << "arr1: " << arr1 << std::endl;
	std::cout << "arr2: " << arr2 << std::endl;
	std::cout << GREEN"---------------------------------------------"RESET << std::endl;
	
	std::cout << NEON_GREEN"\nOut of bounds test:"RESET << std::endl;
	std::cout << "Size of arr2: " << arr2.size() << std::endl;
	std::cout << "arr2: " << arr2 << std::endl;
	try
	{
		std::cout << "Accessing arr2[42] = 69: " << std::endl;
		arr2[42] = 69;
		std::cout << RED"No exception thrown!"RESET << std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << GREEN"✓ Exception catched. Reason: "<< e.what() << RESET << std::endl;
	}
	std::cout << GREEN"---------------------------------------------"RESET << std::endl;

	std::cout << NEON_GREEN"\nArray of strings:"RESET << std::endl;
	Array<std::string> arrStr(3);
	arrStr[0] = "Hello";
	arrStr[1] = "World";
	arrStr[2] = "!";
	
	std::cout << "Size of arrStr: " << arrStr.size() << std::endl;
	std::cout << "arrStr: " << arrStr << std::endl;
	std::cout << GREEN"---------------------------------------------"RESET << std::endl;

	std::cout << NEON_GREEN"\nConst array:"RESET << std::endl;
	const Array<int> arrConst(5);
	std::cout << "Size of arrConst: " << arrConst.size() << std::endl;
	std::cout << "arrConst: " << arrConst << std::endl;
	// ERROR: arrConst[3] = 69;
	std::cout << GREEN"---------------------------------------------"RESET << std::endl;

	std::cout << std::endl;
	std::cout << GREEN"============== End of tests ==============="RESET << std::endl;
	std::cout << std::endl;
	return 0;
}
