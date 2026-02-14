/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 16:21:00 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/02/14 16:28:07 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "Span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

static void	printTestName(const std::string& name)
{
	std::cout << "\n=== " << name << " ===" << std::endl;
}

/*
 *Базовый сценарий (happy path) — всё работает как ожидается
Граничные случаи (edge cases) — минимум/максимум элементов
Исключения (error cases) — проверяем, что правильно бросаются исключения
 */

int	main()
{
	std::cout << NEON_GREEN << "\n=================== TESTS ====================\n" << RESET << std::endl;

	printTestName("Test 1: Basic example from subject");
	

	return 0;
}
