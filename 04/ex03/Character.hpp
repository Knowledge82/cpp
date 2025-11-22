/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:37:32 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/09/01 17:54:48 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define GREEN   "\033[0;32m"
#define RED     "\033[0;31m"
#define RESET   "\033[0m"

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "AMateria.hpp"
#include "ICharacter.hpp"


class	Character : public ICharacter
{
private:
	static const int INVENTORY_SIZE = 4;
	std::string	name;
	AMateria*	inventory[INVENTORY_SIZE];
public:
	Character(const std::string& name);
	Character(const Character& other);
	Character& operator=(const Character& other);
	virtual ~Character();

	virtual const std::string&      getName() const;
	virtual void                    equip(AMateria* m);
	virtual void                    unequip(int idx);
	virtual void                    use(int idx, ICharacter& target);

};

#endif
