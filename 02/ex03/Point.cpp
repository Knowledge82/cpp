/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:23:46 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/20 17:56:06 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

Point::Point(): x_(0), y_(0)
{
	//std::cout << "Point default constructor called" << std::endl;
}

Point::Point(const float x, const float y): x_(x), y_(y)
{
	//std::cout << "Point float constructor called" << std::endl;	
}

Point::Point(const Point& other): x_(other.x_), y_(other.y_)
{
	//std::cout << "Point copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other)
{
	//std::cout << "Point copy assignment operator called" << std::endl;
	// мы НЕ МОЖЕМ изменить const поля
	// оператор практически бесполезен
	// но OCF требует его наличия
	
	(void)other;// подавление warning о неиспользуемом параметре
	return *this;
}

Point::~Point()
{
	//std::cout << "Point destructor called" << std::endl;
}

Fixed	Point::getX(void) const
{
	return this->x_;
}

Fixed	Point::getY(void) const
{
	return this->y_;
}
