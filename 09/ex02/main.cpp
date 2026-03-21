/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:45:17 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/21 18:31:44 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe	pm;
		pm.run(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
