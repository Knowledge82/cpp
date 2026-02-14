/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:49:15 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/02/14 16:19:52 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>

class	Span
{
public:
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void				addNumber(int num);
	int					shortestSpan() const;
	int					longestSpan() const;

	template <typename Iterator>
	void				addRange(Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			if (numbers_.size() >= maxSize_)
				throw std::out_of_range("Span: container is full");

			numbers_.push_back(*begin);
			++begin;
		}
	}

private:
	std::vector<int>	numbers_;
	unsigned int		maxSize_;
};

#endif
