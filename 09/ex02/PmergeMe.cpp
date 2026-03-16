/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:48:51 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/16 18:17:51 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>
#include <sstream>
#include <stdexcept>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{

}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{

}

PmergeMe::~PmergeMe()
{

}

int	PmergeMe::parsePositiveIntStrict(const std::string& s)
{
	if (s.empty())
		throw std::runtime_error("Error");
	if (s.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("Error");
	long acc = 0;
//////////////////////////////////////////////////////

	return static_cast<int>(acc);
}

void	PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		int value = parsePositiveIntStrict(argv[i]);
		vec_.push_back(static_cast<int>(value));
		deq_.push_back(static_cast<int>(value));
	}
}

void	PmergeMe::sortAndDisplay()
{

}

    std::vector<int>    vec_;
    std::deque<int>     deq_;

void    PmergeMe::sortVector();
void    PmergeMe::sortDeque();

