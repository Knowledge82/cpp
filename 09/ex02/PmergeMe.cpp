/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:48:51 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/18 19:10:34 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <limits>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <sys/time.h>
#include <iostream>

PmergeMe::PmergeMe()
{

}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{

	}
	return *this;
}

PmergeMe::~PmergeMe()
{

}

static void	printSequence(const std::vector<int>& v)
{
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << v[i];
	}
}
/*
static void	printSequence(const std::deque<int>& d)
{
	for (size_t i = 0; i < d.size() - 1; ++i)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << d[i];
	}
}
*/
static long long	timestamp()
{
	timeval	tv;
	gettimeofday(&tv, 0);

	return (long long)tv.tv_sec * 1000000LL + (long long)tv.tv_usec;
}

int	PmergeMe::parsePositiveIntStrict(const std::string& s)
{
	if (s.empty())
		throw std::runtime_error("Error");
	if (s.find_first_not_of("0123456789") != std::string::npos)
		throw std::runtime_error("Error");
	long		acc = 0;
	const int	limit = std::numeric_limits<int>::max();
	for (size_t i = 0; i < s.size(); ++i)
	{
		int	digit = s[i] - '0';
		if (acc > (limit - digit) / 10) //safety condition = acc*10+digit<=INT_MAX ->
			throw std::runtime_error("Error");            // acc<=(INT_MAX-digit)/10
		acc = acc * 10 + digit;
	}
	if (acc == 0)
		throw std::runtime_error("Error");
	return static_cast<int>(acc);
}

void	PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		int value = parsePositiveIntStrict(argv[i]);
		vec_.push_back(value);
		deq_.push_back(value);
	}
}

void	PmergeMe::sortAndDisplay()
{
	std::cout << "Before: ";
	printSequence(vec_);
	std::cout << std::endl;
	
	long long	t0 = timestamp();
	sortVector();
	long long	t1 = timestamp();
	
	long long	t2 = timestamp();
	sortDeque();
	long long	t3 = timestamp();

	std::cout << "After: ";
	printSequence(vec_);
	std::cout << std::endl;

	std::cout << "Time to process a range of " << vec_.size() << " elements with std::vector : " << t1 - t0 << " us" << std::endl;
	std::cout << "Time to process a range of " << deq_.size() << " elements with std::deque : " << t3 - t2 << " us" << std::endl;

}

void    PmergeMe::sortVector()
{
	std::sort(vec_.begin(), vec_.end());
}

void    PmergeMe::sortDeque()
{
	std::sort(deq_.begin(), deq_.end());
}




