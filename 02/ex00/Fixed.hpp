/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 15:46:39 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/19 13:09:00 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class	Fixed
{
private:
	int			rawBits_;
	static const int	fractionalBits_ = 8;

public:
	//Orthodox Canonical Form
	
	Fixed(); //Default constructor
	
	Fixed(const Fixed& other); //Copy constructor
	
	Fixed& operator=(const Fixed& other); // Copy assigment operator
	
	~Fixed(); //Destructor

	//Getters
	int	getRawBits(void) const;

	//Setters
	void	setRawBits(int const raw);
};

#endif
