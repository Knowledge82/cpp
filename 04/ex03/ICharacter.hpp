/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 19:22:16 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/30 20:13:51 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ICHARACTER_HPP
#define ICHARACTER_HPP

#include <string>
#include "AMateria.hpp"

class	ICharacter
{
public:
	virtual	~ICharacter() {}
	virtual const std::string&	getName() const = 0;
	virtual void			equip(AMateria* m) = 0;
	virtual void			unequip(int idx) = 0;
	virtual void			use(int idx, ICharacter& target) = 0;
};

#endif
