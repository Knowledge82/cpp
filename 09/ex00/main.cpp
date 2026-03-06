/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 11:05:32 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/06 14:00:05 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "BitcoinExchange.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	std::cout << NEON_GREEN << "\n======================== TESTS ========================\n" << std::endl; 
	
	try
	{
		BitcoinExchange	btc;
		btc.loadDB("data.csv");
		btc.processInput(argv[1]);
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << NEON_GREEN << "\n======================== END OF TESTS ========================\n" << std::endl; 
	return 0;
}
