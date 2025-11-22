/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 20:04:55 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/30 20:14:15 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"

class	IMateriaSource
{
public:
	virtual			~IMateriaSource() {}
	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria*	createMateria(const std::string& type) = 0;
};

#endif
