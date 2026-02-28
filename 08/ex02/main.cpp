/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:19:42 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/02/28 15:01:54 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "MutantStack.hpp"
#include <iostream>
#include <string>
#include <list>

static void	printTestName(const std::string& name)
{
	std::cout << GREEN << "\n===" << name << "===" << RESET << std::endl;
}

static void	printStackConst(const MutantStack<int>& mStack)
{
	std::cout << "Const iteration: " << std::endl;
	MutantStack<int>::const_iterator cIt = mStack.begin();
	MutantStack<int>::const_iterator cIte = mStack.end();

	while (cIt != cIte)
	{
		std::cout << *cIt << std::endl;
		++cIt;
	}
}

int	main()
{
	std::cout << NEON_GREEN << "\n=================== TESTS ==================" << RESET << std::endl;

	printTestName("Test 1: default test from subject");

	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::stack<int> s(mstack);
//------------------------------------------------------

	printTestName("Test 2: comparing with std::list");

	std::list<int>	lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << lst.back() << std::endl;
	lst.pop_back();
	std::cout << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator l_it = lst.begin();
	std::list<int>::iterator l_ite = lst.end();
	
	while (l_it != l_ite)
	{
		std::cout << *l_it << std::endl;
		++l_it;
	}
//------------------------------------------------------

	printTestName("Test 3: reverse iteration");

	MutantStack<int>	ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);

	std::cout << "Normal iteration: begin() -> end()" << std::endl;
	for (MutantStack<int>::iterator msIt = ms.begin(); msIt != ms.end(); ++msIt)
	{
		std::cout << *msIt << std::endl;
	}

	std::cout << std::endl;	
	
	std::cout << "Reverse iteration: rbegin() -> rend()" << std::endl;
	for (MutantStack<int>::reverse_iterator msRevIt = ms.rbegin(); msRevIt != ms.rend(); ++msRevIt)
	{
		std::cout << *msRevIt << std::endl;
	}
//------------------------------------------------------

	printTestName("Test 4: const iterators");

	MutantStack<int>	cMs;
	cMs.push(10);
	cMs.push(20);
	cMs.push(30);

	printStackConst(cMs);
//------------------------------------------------------
	
	printTestName("Test 5: OCF - copy and assignment");
	
	MutantStack<int>	original;
	original.push(1);
	original.push(2);
	original.push(3);

	std::cout << "Original mutant stack: " << std::endl;
	for (MutantStack<int>::iterator i = original.begin(); i != original.end(); ++i)
	{
		std::cout << *i << std::endl;
	}

	std::cout << "Copying stack..." << std::endl;
	MutantStack<int>	copied(original);
	std::cout << "Copied top: " << copied.top() << std::endl;
	
	MutantStack<int>	assigned;
	assigned = original;
	std::cout << "Assigned top: " << assigned.top() << std::endl;

	std::cout << std::endl;	
	
	std::cout << "Adding *69* to the top of original" << std::endl;
	original.push(69);

	std::cout << "Original top: " << original.top() << std::endl;
	std::cout << "Copied top (expects unchanged): " << copied.top() << std::endl;
	std::cout << "Assigned top (expects unchanged): " << assigned.top() << std::endl;
//------------------------------------------------------

	std::cout << NEON_GREEN << "\n=================== END OF TESTS ==================\n" << RESET << std::endl;
	return 0;
}
