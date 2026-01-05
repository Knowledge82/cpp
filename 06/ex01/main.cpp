/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 13:15:10 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/02 15:45:43 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET		"\033[0m"
#define RED		"\033[31m"
#define GREEN		"\033[32m"
#define YELLOW		"\033[33m"
#define BLUE		"\033[34m"
#define MAGENTA		"\033[35m"
#define CYAN		"\033[36m"
#define NEON_GREEN	"\033[92m"

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main()
{
	Data original;

	original.id = 69;
	original.name = "Valera";
	std::cout << std::endl;

	std::cout << GREEN"===== Original data ====="RESET << std::endl;
	std::cout << std::endl;
	std::cout << "id: " << original.id << std::endl;
	std::cout << "name: " << original.name << std::endl;
	std::cout << "ptr: " << &original << std::endl;
	std::cout << std::endl;

	std::cout << GREEN"===== Serialize ====="RESET << std::endl;
	std::cout << std::endl;
	uintptr_t serialized = Serializer::serialize(&original);
	std::cout << "serialized ptr: " << serialized << std::endl;
	std::cout << std::endl;

	std::cout << GREEN"===== Deserialize ====="RESET << std::endl;
	std::cout << std::endl;
	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "deserialized ptr: " << deserialized << std::endl;
	std::cout << std::endl;

	std::cout << GREEN"===== Compare ====="RESET << std::endl;
	std::cout << std::endl;
	if (&original == deserialized)
		std::cout << "✅ original ptr = deserialized ptr" << std::endl;
	else
		std::cout << "❌ original ptr != deserialized ptr" << std::endl;
	std::cout << std::endl;

	return 0;

}
