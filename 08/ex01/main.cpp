/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:21:00 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/02/15 18:40:00 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>

static void	printTestName(const std::string& name)
{
	std::cout << GREEN << "\n=== " << name << " ===" << RESET << std::endl;
}

int	main()
{
	std::cout << NEON_GREEN << "\n=================== TESTS ====================" << RESET << std::endl;

	printTestName("Test 1: Basic example from subject");
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
//-------------------------------------------------------	
	printTestName("Test 2: Exception on overflow");
	try
	{
		Span sp(3);

		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);

		std::cout << "Trying to add 4th element to Span(3)..." << std::endl;
		sp.addNumber(4); // exception throw expected

		std::cout << RED << "ERROR: Exception was NOT thrown!" << RESET << std::endl;
	}
	catch (const std::length_error& e)
	{
		std::cout << "OK: correct type of exception was thrown and cached. " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Wrong type of exception: " << e.what() << RESET << std::endl;
	}
//-------------------------------------------------------	
	printTestName("Test 3: Exception with not enough elements");
	try
	{
		Span sp(10);
		
		std::cout << "Trying to shortestSpan() on empty span..." << std::endl;
		sp.shortestSpan(); 	// empty span! exception throw expected

		std::cout << RED << "ERROR: Exception was NOT thrown!" << RESET << std::endl;	
	}
	catch (const  std::invalid_argument& e)
	{
		std::cout << "OK: correct type of exception was thrown and cached. " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Wrong type of exception: " << e.what() << RESET << std::endl;
	}
	
	std::cout << std::endl;
	
	try
	{
		Span sp(10);
		sp.addNumber(69);
		
		std::cout << "Trying to longestSpan() on span with 1 element..." << std::endl;
		sp.longestSpan(); 	// exception throw expected

		std::cout << RED << "ERROR: Exception was NOT thrown!" << RESET << std::endl;	
	}
	catch (const  std::invalid_argument& e)
	{
		std::cout << "OK: correct type of exception was thrown and cached. " << e.what() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Wrong type of exception: " << e.what() << RESET << std::endl;
	}
//-------------------------------------------------------	
	printTestName("Test 4: Edge case - exactly 2 elements");
	try
	{
		Span sp(2);
		
		sp.addNumber(10);
		sp.addNumber(20);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		// in span with 2 elements shortest == longest
		if (sp.shortestSpan() == sp.longestSpan())
			std::cout << "OK: shortest == longest (as expected with 2 elements)" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
//-------------------------------------------------------	
	printTestName("Test 5: Duplicates");
	try
	{
		Span sp(5);
		
		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(5);
		sp.addNumber(10);
		sp.addNumber(10);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
//-------------------------------------------------------	
	printTestName("Test 6: Negative numbers");
	try
	{
		Span sp(5);
		
		sp.addNumber(-10);
		sp.addNumber(-5);
		sp.addNumber(0);
		sp.addNumber(5);
		sp.addNumber(10);
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
//-------------------------------------------------------	
	printTestName("Test 7: addRange() with small range, benefits of template realization");
	try
	{
		Span sp(10);

		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		
		std::list<int> lst;
		lst.push_back(6);
		lst.push_back(7);
		lst.push_back(8);
		lst.push_back(9);
		lst.push_back(10);

		sp.addRange(vec.begin(), vec.end());
		sp.addRange(lst.begin(), lst.end());

		std::cout << "Added " << vec.size() + lst.size() << " elements via addRange(): ";
		std::cout << vec.size() << " from <vector> and " << lst.size() << " from <list>" << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error: " << e.what() << RESET << std::endl;
	}
//-------------------------------------------------------	
	printTestName("Test 8: addRange() overflow");
	try
	{
		Span sp(3);

		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		vec.push_back(5);
		
		std::cout << "Trying to add 5 elements span(3)..." << std::endl;
		sp.addRange(vec.begin(), vec.end()); //exception expected
		
		std::cout << RED << "ERROR: Exception was NOT thrown!" << RESET << std::endl;	
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error(exception): " << e.what() << RESET << std::endl;
	}
//-------------------------------------------------------	
	printTestName("Test 9: Large span (10,000 elements)");
	try
	{
		const unsigned int SIZE = 10000;
		Span sp(SIZE);
		
		std::cout << "Generating " << SIZE << " random numbers..." << std::endl;
		std::srand(std::time(0)); // init random generator, setting seed.

		for (unsigned int i = 0; i < SIZE; ++i)
			sp.addNumber(std::rand());

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
		std::cout << std::endl;
		std::cout << "OK: Successfully handled " << SIZE << " elements" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error(exception): " << e.what() << RESET << std::endl;
		
	}
//-------------------------------------------------------	
	printTestName("Test 10: Very large span via addRange() (100,000 elements)");
	try
	{
		const unsigned int SIZE = 100000;
		Span sp(SIZE);
		
		std::cout << "Generating " << SIZE << " random numbers..." << std::endl;
		std::vector<int> vec;
		vec.reserve(SIZE);
		
		std::srand(std::time(0)); // init random generator, setting seed.
		for (unsigned int i = 0; i < SIZE; ++i)
			vec.push_back(std::rand());

		std::cout << "Adding via addRange()..." << std::endl;
		sp.addRange(vec.begin(), vec.end());
		
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
		
		std::cout << std::endl;
		std::cout << "OK: Successfully handled " << SIZE << " elements" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error(exception): " << e.what() << RESET << std::endl;
		
	}

//-------------------------------------------------------	
	printTestName("Test 11: Copy constructor and assignment operator");
	try
	{
		Span sp1(5);
		sp1.addNumber(10);
		sp1.addNumber(20);
		sp1.addNumber(30);

		Span sp2(sp1);
		std::cout << "sp2 (copy of sp1) - shortest: " << sp2.shortestSpan() << std::endl;
		std::cout << "sp2 (copy of sp1) - longest: " << sp2.longestSpan() << std::endl;

		Span sp3(10);
		sp3 = sp1;
		std::cout << "sp3 (assigned from sp1) - longest: " << sp3.longestSpan() << std::endl;

		sp1.addNumber(69);
		std::cout << "After adding to sp1, sp2 longest(expecting the same): " << sp2.longestSpan() << std::endl;
		
		std::cout << "OK: Copy constructor and assignment operator successfully tested" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << "Error(exception): " << e.what() << RESET << std::endl;
	}
		
	std::cout << NEON_GREEN << "\n=================== END OF TESTS ====================\n" << RESET << std::endl;
	return 0;
}
