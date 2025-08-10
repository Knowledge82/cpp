/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 19:36:11 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/09 19:58:22 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	//src
	std::string	brain = "HI THIS IS BRAIN";
	
	//pointer
	std::string*	stringPTR = &brain;
	
	//reference
	std::string&	stringREF = brain;

	std::cout << "======= MEMORY ADDRESS ========" << std::endl;
	std::cout << "Memory adress of SRC string: " << &brain << std::endl;
	std::cout << "Memory Address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory Address of stringREF: " << &stringREF << std::endl;

	std::cout << "\n======== VALUES =========" << std::endl;
	std::cout << "Value of SRC string:         " << brain << std::endl;
	std::cout << "Value of stringPTR:          " << *stringPTR << std::endl;
	std::cout << "Value of stringREF:          " << stringREF << std::endl;

	// more info
	std::cout << "\n======== Additional info =========" << std::endl;
	std::cout << "Address of stringPTR itself: " << &stringPTR << std::endl;
	std::cout << "Size of SRC string:          " << sizeof(brain) << std::endl;
	std::cout << "Size of pointer:             " << sizeof(stringPTR) << std::endl;
	std::cout << "Size of reference:           " << sizeof(stringREF) << std::endl;

	return 0;
}
