/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:37:25 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/18 18:10:22 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class	Array
{
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array&		operator=(const Array& other);
	~Array();

	T&			operator[](unsigned int index);
	const T&	operator[](unsigned int other) const;
	
	unsigned int size() const;

private:
	T*				data_;
	unsigned int	size_;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
	os << "[";
	for (unsigned int i = 0; i < arr.size(); i++)
	{
		os << arr[i];
		if (i < arr.size() - 1)
			os << ", ";
	}
	os << "]";
	return os;
}

#include "Array.tpp"

#endif
