/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:46:28 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/20 14:52:49 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void	test_bsp()
{
	std::cout << "\n====== BSP TESTS ======" << std::endl;

	Point	a(0.0f, 0.0f);
	Point	b(10.0f, 0.0f);
	Point	c(5.0f, 10.0f);

	std::cout << "A(" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "B(" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "C(" << c.getX() << ", " << c.getY() << ")" << std::endl;

	//Test 1: point inside
	Point	inside(5.0f, 3.0f);
	std::cout << "\nPoint(" << inside.getX() << ", " << inside.getY() << ") inside: "
			<< (bsp(a, b, c, inside) ? "TRUE" : "FALSE") << std::endl;
	
	//Test 2: point outside
	Point	outside(15.0f, 5.0f);
	std::cout << "Point(" << outside.getX() << ", " << outside.getY() << ") inside: "
			<< (bsp(a, b, c, outside) ? "TRUE" : "FALSE") << std::endl;
	
	//Test 3: point on vertex (se espera FALSE)
	std::cout << "Point on vertex A inside: "
			<< (bsp(a, b, c, a) ? "TRUE" : "FALSE") << std::endl;
	
	//Test 4: point on edge (se espera FALSE)
	Point	on_edge(5.0f, 0.0f); // edge AB
	std::cout << "Point on edge(" << on_edge.getX() << ", " << on_edge.getY() << ") inside: "
			<< (bsp(a, b, c, on_edge) ? "TRUE" : "FALSE") << "\n" << std::endl;	
}

int	main(void)
{
	test_bsp();

	return 0;
}
