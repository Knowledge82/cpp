/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:45:17 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/17 18:09:35 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error\n";
		return 1;
	}

	PmergeMe	pm;

	//parse and fill both containers
	pm.parseInput(argc, argv);
	//start algos and print result
	pm.sortAndDisplay();

	return 0;
}
