/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:07:01 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/02/15 14:45:20 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : maxSize_(n)
{
	numbers_.reserve(n); // optimization for avoid multiplies realocations and copy
}

Span::Span(const Span& other) : numbers_(other.numbers_), maxSize_(other.maxSize_)
{
	// std::vector is already doing deep copy
}
	
Span& Span::operator=(const Span& other)
{
	if (this == &other)
		return *this;
	numbers_ = other.numbers_;
	maxSize_ = other.maxSize_;
	return *this;
}
	
Span::~Span()
{

}

void	Span::addNumber(int num)
{
	if (numbers_.size() >= maxSize_)
		throw std::length_error("Span: container is full"); // or std::out_of_range(). Both is valid.
	numbers_.push_back(num);
}

int		Span::shortestSpan() const
{
	if (numbers_.size() < 2)
		throw std::invalid_argument("Span: not enough elements to calculate span");

	std::vector<int> sorted = numbers_;
	std::sort(sorted.begin(), sorted.end());

	int minSpan = sorted[1] - sorted[0]; // start value
	
	for (std::vector<int>::const_iterator it = sorted.begin(); it != sorted.end() - 1; ++it)
	{
		int diff = *(it + 1) - *it;
		if (diff < minSpan)
			minSpan = diff;
	}

	return minSpan;
}

int		Span::longestSpan() const
{
	if (numbers_.size() < 2)
		throw std::invalid_argument("Span: not enough elements to calculate span");

	std::vector<int>::const_iterator minIt = std::min_element(numbers_.begin(), numbers_.end());
	std::vector<int>::const_iterator maxIt = std::max_element(numbers_.begin(), numbers_.end());

	return *maxIt - *minIt;
}

