/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:48:51 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/21 18:34:51 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <iomanip>
#include <limits>
#include <stdexcept>
#include <algorithm>
#include <sys/time.h>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{
		inputVec_ = other.inputVec_;
		inputDeq_ = other.inputDeq_;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

long long	PmergeMe::nowMicroseconds()
{
	timeval	tv;
	gettimeofday(&tv, 0);

	return static_cast<long long>(tv.tv_sec) * 1000000LL
		+ static_cast<long long>(tv.tv_usec);
}

void		PmergeMe::printSequence(const std::vector<int>& seq)
{
	for (std::size_t i = 0; i < seq.size(); ++i)
	{
		if (i > 0)
			std::cout << " ";
		std::cout << seq[i];
	}
}

int			PmergeMe::parsePositiveIntStrict(const std::string& s)
{
	if (s.empty() || s.find_first_not_of("0123456789") != std::string::npos)
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
	if (acc <= 0)
		throw std::runtime_error("Error");
	return static_cast<int>(acc);
}

std::vector<int>		PmergeMe::parseToVector(int argc, char **argv)
{
	std::vector<int>	vec;
	for (int i = 1; i < argc; ++i)
		vec.push_back(parsePositiveIntStrict(argv[i]));
	return vec;
}

std::deque<int>		PmergeMe::parseToDeque(int argc, char **argv)
{
	std::deque<int>	deq;
	for (int i = 1; i < argc; ++i)
		deq.push_back(parsePositiveIntStrict(argv[i]));
	return deq;
}

std::vector<std::size_t>	PmergeMe::jacobshtalInsertionOrder(std::size_t n)
{
	std::vector<std::size_t>	order;
	if (n == 0)
		return order;

	std::vector<size_t>	jacob;
	jacob.push_back(1);
	jacob.push_back(3);
	while (jacob.back() < n)
	{
		std::size_t	sz = jacob.size();
		std::size_t	next = jacob[sz - 1] + 2 * jacob[sz - 2];
		jacob.push_back(next);
	}

	std::size_t	prev = 1;
	for (size_t k = 1; k < jacob.size(); ++k)
	{
		std::size_t	current = jacob[k];
		if (current > n)
			current = n;
		for (std::size_t x = current; x > prev; --x)
			order.push_back(x);
		if (current == n)
			break;
		prev = jacob[k];
	}

	if (order.empty())
	{
		for (std::size_t idx = 2; idx <= n; ++idx)
			order.push_back(idx);
		return order;
	}

	std::vector<bool>	used(n + 1, false);
	used[1] = true;
	for (std::size_t i = 0; i < order.size(); ++i)
	{
		if (order[i] <= n)
			used[order[i]] = true;
	}
	for (std::size_t idx = 2; idx <= n; ++idx)
	{
		if (!used[idx])
			order.push_back(idx);
	}
	return order;
}

// Ford-Johnson for std::vector
std::vector<int> 			PmergeMe::fordJohnsonVector(const std::vector<int>& input)
{
	if (input.size() <= 1)
		return input;

	bool				hasStraggler = (input.size() % 2 != 0);
	int					straggler = 0;
	if (hasStraggler)
		straggler = input.back();

	// 1. make pairs
	std::vector<Pair>	pairs;
	for (std::size_t i = 0; i + 1 < input.size(); i += 2)
		pairs.push_back(Pair(input[i], input[i + 1]));

	// 2. recurs sort of winners
	std::vector<int> winners;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].winner);
	std::vector<int>	sortedWinners = fordJohnsonVector(winners);

	// 3. Восстанавливаем основную цепочку (mainChain) и список ожидающих (pending) 
	std::vector<int>	mainChain;
	std::vector<int>	pending;
	std::vector<bool>	used(pairs.size(), false);

	for (std::size_t i = 0; i < sortedWinners.size(); ++i)
	{
		int			w = sortedWinners[i];
		std::size_t	idx = 0;
		while (idx < pairs.size())
		{
			if (!used[idx] && pairs[idx].winner == w)
				break;
			++idx;
		}
		if (idx == pairs.size())
		{
			++i;
			continue;
		}
		used[idx] = true;
		if (i == 0)
			mainChain.push_back(pairs[idx].loser); //b1
		mainChain.push_back(pairs[idx].winner); //a1, a2, ...
		if (i > 0)
			pending.push_back(pairs[idx].loser); // b2, b3, ...
	}

	// 4. Вставка из pending в порядке Якобсталя
	std::vector<std::size_t>	order = jacobshtalInsertionOrder(pending.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		std::size_t	idx = order[i];
		if (idx >= 1 && idx <= pending.size())
		{
			int	val = pending[idx - 1];
			std::vector<int>::iterator it = std::upper_bound(mainChain.begin(), mainChain.end(), val); 
			mainChain.insert(it, val);
		}
	}

	// 5. Вставка хвоста
	if (hasStraggler)
	{
		std::vector<int>::iterator it = std::upper_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}

	return mainChain;
}

std::deque<int>			PmergeMe::fordJohnsonDeque(const std::deque<int>& input)
{
	if (input.size() <= 1)
		return input;

	bool	hasStraggler = (input.size() % 2 != 0);
	int		straggler = 0;
	if (hasStraggler)
		straggler = input.back();

	std::deque<Pair>	pairs;
	for (std::size_t i = 0; i + 1 < input.size(); i += 2)
		pairs.push_back(Pair(input[i], input[i + 1]));

	std::deque<int> winners;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].winner);
	std::deque<int>	sortedWinners = fordJohnsonDeque(winners);

	std::deque<int>	mainChain;
	std::deque<int>	pending;
	std::vector<bool>	used(pairs.size(), false);

	for (std::size_t i = 0; i < sortedWinners.size(); ++i)
	{
		int			w = sortedWinners[i];
		std::size_t	idx = 0;
		while (idx < pairs.size())
		{
			if (!used[idx] && pairs[idx].winner == w)
				break;
			++idx;
		}
		if (idx == pairs.size())
		{
			++i;
			continue;
		}
		used[idx] = true;
		if (i == 0)
			mainChain.push_back(pairs[idx].loser); //b1
		mainChain.push_back(pairs[idx].winner); //a1, a2, ...
		if (i > 0)
			pending.push_back(pairs[idx].loser); // b2, b3, ...
	}

	std::vector<std::size_t>	order = jacobshtalInsertionOrder(pending.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		std::size_t	idx = order[i];
		if (idx >= 1 && idx <= pending.size())
		{
			int	val = pending[idx - 1];
			std::deque<int>::iterator it = std::upper_bound(mainChain.begin(), mainChain.end(), val); 
			mainChain.insert(it, val);
		}
	}

	// 5. Вставка хвоста
	if (hasStraggler)
	{
		std::deque<int>::iterator it = std::upper_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}

	return mainChain;
}

bool		PmergeMe::isSorted(const std::vector<int>& v)
{
	if (v.size() < 2)
		return true;
	for (std::size_t i = 1; i < v.size(); ++i)
	{
		if (v[i - 1] > v[i])
			return false;
	}
	return true;
}

bool		PmergeMe::isSorted(const std::deque<int>& d)
{
	if (d.size() < 2)
		return true;
	for (std::size_t i = 1; i < d.size(); ++i)
	{
		if (d[i - 1] > d[i])
			return false;
	}
	return true;
}

void		PmergeMe::run(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error");
	
	long long	t0 = nowMicroseconds();
	inputVec_ = parseToVector(argc, argv);
	std::vector<int>	sortedVec = fordJohnsonVector(inputVec_);
	long long	t1 = nowMicroseconds();

	long long	t2 = nowMicroseconds();
	inputDeq_ = parseToDeque(argc, argv);
	std::deque<int>	sortedDeq = fordJohnsonDeque(inputDeq_);
	long long	t3 = nowMicroseconds();

	if (!isSorted(sortedVec) || !isSorted(sortedDeq))
		throw std::runtime_error("Error");

	std::cout << "Before: ";
	printSequence(inputVec_);
	std::cout << std::endl;

	std::cout << "After: ";
	printSequence(sortedVec);
	std::cout << std::endl;

	std::cout << "Time to process a range of " << inputVec_.size()
			<< " elements with std::vector : " << std::fixed << std::setprecision(5)
			<< static_cast<double>(t1 - t0) << " us" << std::endl;
	std::cout << "Time to process a range of " << inputDeq_.size()
			<< " elements with std::deque : " << std::fixed << std::setprecision(5)
			<< static_cast<double>(t3 - t2) << " us" << std::endl;
}
