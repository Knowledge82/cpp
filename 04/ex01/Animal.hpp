/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 11:47:16 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/25 17:18:43 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define GREEN	"\033[0;32m"
#define RED	"\033[0;31m"
#define RESET	"\033[0m"

#include <string>

class	Animal
{
protected:
	std::string	type;

public:
	Animal();
	Animal(const Animal& other);
	Animal& operator=(const Animal& other);
	virtual ~Animal();

	virtual void	makeSound() const;
	std::string	getType() const;
	
};

#endif
