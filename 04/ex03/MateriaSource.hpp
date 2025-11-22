/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:24:19 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/31 17:18:26 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>
#include "AMateria.hpp"
#include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
private:
	static const int	TEMPLATES_COUNT = 4;
	AMateria*		templates[TEMPLATES_COUNT];

public:
	MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);
	virtual ~MateriaSource();

	virtual void		learnMateria(AMateria*);
	virtual AMateria*	createMateria(const std::string& type);

};

#endif
