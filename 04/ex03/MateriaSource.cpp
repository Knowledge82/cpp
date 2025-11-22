/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:37:55 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/31 18:39:29 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < TEMPLATES_COUNT; i++)
	{
		templates[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	for (int i = 0; i < TEMPLATES_COUNT; i++)
		templates[i] = NULL;
	for (int i = 0; i < TEMPLATES_COUNT; i++)
	{
		if (other.templates[i] != NULL)
			templates[i] = other.templates[i]->clone();
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	if (this != &other)
	{
		for (int i = 0; i < TEMPLATES_COUNT; i++)
		{
			delete templates[i];
			templates[i] = NULL;
			if (other.templates[i] != NULL)
				templates[i] = other.templates[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < TEMPLATES_COUNT; i++)
	{
		delete templates[i];
		templates[i] = NULL;
	}
}

void		MateriaSource::learnMateria(AMateria* m)
{
	if (m == NULL)
		return;
	for (int i = 0; i < TEMPLATES_COUNT; i++)
	{
		if (templates[i] == NULL)
		{
			templates[i] = m->clone();
			return;
		}
	}
}

AMateria*	MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < TEMPLATES_COUNT; i++)
	{
		if (templates[i] != NULL && templates[i]->getType() == type)
			return templates[i]->clone();
	}
	return NULL;
}

