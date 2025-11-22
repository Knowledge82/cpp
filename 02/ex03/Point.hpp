/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 15:23:39 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/20 13:18:57 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point
{
private:
	Fixed const	x_;
	Fixed const	y_;

public:
	// OCF:
	Point();
	Point(const float x, const float y);
	Point(const Point& other);
	Point& operator=(const Point& other);
	~Point();

	// Getters:
	Fixed	getX(void) const;
	Fixed	getY(void) const;
};

// BSP function
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
