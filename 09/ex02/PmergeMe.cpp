/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:48:51 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/23 17:12:21 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.hpp"
#include "PmergeMe.hpp"

#include <iostream>
#include <iomanip>
#include <sstream>
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

std::string	PmergeMe::formatDuration(long long microseconds)
{
	std::ostringstream	oss;
	oss << std::fixed << std::setprecision(3);

	if (microseconds < 1000)
		oss << static_cast<double>(microseconds) << " us";
	else if (microseconds < 1000000)
		oss << (static_cast<double>(microseconds) / 1000.0) << " ms";
	else
		oss << (static_cast<double>(microseconds) / 1000000) << " s";
	
	return oss.str();
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
	std::vector<int>			vec;
	for (int i = 1; i < argc; ++i)
		vec.push_back(parsePositiveIntStrict(argv[i]));
	return vec;
}

std::deque<int>		PmergeMe::parseToDeque(int argc, char **argv)
{
	std::deque<int>				deq;
	for (int i = 1; i < argc; ++i)
		deq.push_back(parsePositiveIntStrict(argv[i]));
	return deq;
}

std::vector<std::size_t>	PmergeMe::jacobshtalInsertionOrder(std::size_t n)
{
	if (n == 0)
		return std::vector<std::size_t>();

	std::vector<std::size_t>	jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < n)
	{
		std::size_t				sz = jacob.size();
		jacob.push_back(jacob[sz - 1] + 2 * jacob[sz - 2]);
	}

	std::vector<std::size_t>	order;
	std::vector<bool>			used(n + 1, false);

	for (std::size_t k = 2; k < jacob.size(); ++k)
	{
		std::size_t				hi = jacob[k];
		std::size_t				lo = jacob[k - 1] + 1;
		if (hi > n)
			hi = n;

		// вставляем от hi вниз до lo
		if (hi < lo)
			continue;
		for (std::size_t x = hi; ; --x)
		{
			if (!used[x])
			{
				order.push_back(x);
				used[x] = true;
			}
			if (x == lo)
				break;
		}
		if (hi == n)
			break;
	}
	// добираем, если что-то осталось
	for (std::size_t x = 1; x <= n; ++x)
		if (!used[x])
			order.push_back(x);
	
	if (order.size() != n)
		throw std::runtime_error("Internal error");
	
	return order;
}

// Ford-Johnson for std::vector
std::vector<int> 			PmergeMe::fordJohnsonVector(const std::vector<int>& input)
{
	if (input.size() <= 1)
		return input;

	bool						hasStraggler = (input.size() % 2 != 0);
	int							straggler = hasStraggler ? input.back() : 0;

	// 1. make pairs
	std::vector<Pair>			pairs;
	for (std::size_t i = 0; i + 1 < input.size(); i += 2)
		pairs.push_back(Pair(input[i], input[i + 1]));

	// 2. recurs sort of winners
	std::vector<int>			 winners;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].winner);
	std::vector<int>			sortedWinners = fordJohnsonVector(winners);

	// 3. make mainChain + pending
	// mainChain:	b1, a1, a2, a3, ...
	// pending:		b2, b3, b4, ...
	// запоминаем позиции a_k в mainChain (до вставки pending)
	std::vector<int>			mainChain;
	std::vector<Pending>		pending;
	std::vector<bool>			used(pairs.size(), false);
	std::vector<std::size_t>	pairIdx(sortedWinners.size());

	for (std::size_t i = 0; i < sortedWinners.size(); ++i)
	{
		int						w = sortedWinners[i];
		std::size_t				idx = 0;
		while (idx < pairs.size() && (used[idx] || pairs[idx].winner != w))
			++idx;
		if (idx == pairs.size())
			throw std::runtime_error("Internal error");
		used[idx] = true;
		pairIdx[i] = idx;
	}

	// mainChain =  b1, a1, a2, a3, ...
	mainChain.push_back(pairs[pairIdx[0]].loser);	// b1
	for (std::size_t i = 0; i < sortedWinners.size(); ++i)
		mainChain.push_back(sortedWinners[i]);		// a1, a2, ...

	// pending = b2, b3, ...
	for (std::size_t i = 1; i < sortedWinners.size(); ++i)
	{
		int	loser = pairs[pairIdx[i]].loser;
		int	wbound = pairs[pairIdx[i]].winner;
		pending.push_back(Pending(loser, wbound));
	}
	
	// 4. Jacobsthal + bounded insertion по winnerBound
	std::vector<std::size_t>	order = jacobshtalInsertionOrder(pending.size());

	for (size_t i = 0; i < order.size(); ++i)
	{
		std::size_t				kidx = order[i]; // 1-based index in pending
		if (kidx < 1 || kidx > pending.size())
			throw std::runtime_error("Internal error");

		const Pending&			item = pending[kidx - 1];

		std::vector<int>::iterator bound =
			std::lower_bound(mainChain.begin(), mainChain.end(), item.winnerBound);
		if (bound == mainChain.end() || *bound != item.winnerBound)
			throw std::runtime_error("Internal error");
		
		std::vector<int>::iterator it =
			std::upper_bound(mainChain.begin(), bound, item.loser);
			mainChain.insert(it, item.loser);
	}

	// 5. Вставка хвоста
	if (hasStraggler)
	{
		std::vector<int>::iterator it =
			std::upper_bound(mainChain.begin(), mainChain.end(), straggler);
		mainChain.insert(it, straggler);
	}

	return mainChain;
}

std::deque<int>			PmergeMe::fordJohnsonDeque(const std::deque<int>& input)
{
	if (input.size() <= 1)
		return input;

	bool						hasStraggler = (input.size() % 2 != 0);
	int							straggler = hasStraggler ? input.back() : 0;

	// 1. Pairs
	std::deque<Pair>			pairs;
	for (std::size_t i = 0; i + 1 < input.size(); i += 2)
		pairs.push_back(Pair(input[i], input[i + 1]));

	// 2. recurs sort of winners
	std::deque<int>				winners;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		winners.push_back(pairs[i].winner);
	std::deque<int>				sortedWinners = fordJohnsonDeque(winners);

	// 3. restore mapping sortedWinners - pairs
	std::vector<bool>			used(pairs.size(), false);
	std::vector<std::size_t>	pairIdx(sortedWinners.size());

	for (std::size_t i = 0; i < sortedWinners.size(); i++)
	{
		int						w = sortedWinners[i];
		std::size_t				idx = 0;

		while (idx < pairs.size() && (used[idx] || pairs[idx].winner != w))
			++idx;
		if (idx == pairs.size())
			throw std::runtime_error("Internal error");
		used[idx] = true;
		pairIdx[i] = idx;
	}

	// build mainChain and pending
	// mainChain: b1, a1, a2, ...
	// pending: {b2, a2}, {b3, a3}, ...
	
	std::deque<int>				mainChain;
	std::deque<Pending>			pending;

	mainChain.push_back(pairs[pairIdx[0]].loser); // b1
	for (std::size_t i = 0; i < sortedWinners.size(); ++i)
		mainChain.push_back(sortedWinners[i]); // a1, a2, ...

	for (std::size_t i = 1; i < sortedWinners.size(); ++i)
	{
		int loser = pairs[pairIdx[i]].loser;
		int wbound = pairs[pairIdx[i]].winner;
		pending.push_back(Pending(loser, wbound));
	}

	// 5. Jacobshtal insertion order over pending indices [1..n]
	std::vector<std::size_t>	order = jacobshtalInsertionOrder(pending.size());
	if (order.size() != pending.size())
		throw std::runtime_error("Internal error");

	// 6. bounded insertion
	for (std::size_t i = 0; i < order.size(); ++i)
	{
		std::size_t	kidx = order[i];
		if (kidx < 1 || kidx > pending.size())
			throw std::runtime_error("Internal error");

		const Pending&			item = pending[kidx - 1];

		std::deque<int>::iterator bound =
			std::lower_bound(mainChain.begin(), mainChain.end(), item.winnerBound);

		if (bound == mainChain.end() || *bound != item.winnerBound)
			throw std::runtime_error("Internal error");
		
		std::deque<int>::iterator pos =
			std::upper_bound(mainChain.begin(), bound, item.loser);
		mainChain.insert(pos, item.loser);
	}

	// 7. Вставка хвоста
	if (hasStraggler)
	{
		std::deque<int>::iterator it =
			std::upper_bound(mainChain.begin(), mainChain.end(), straggler);
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
	else
		std::cout << GREEN <<"Both containers are successfully sorted" << RESET << std::endl;

	std::cout << GREEN << "Before: " << RESET;
	printSequence(inputVec_);
	std::cout << std::endl;

	std::cout << GREEN << "After: " << RESET;
	printSequence(sortedVec);
	std::cout << std::endl;


	long long	elapsedVec = t1 - t0;
	long long	elapsedDeq = t3 - t2;
	std::cout << "Time to process a range of " << inputVec_.size()
			<< " elements with std::vector : " << formatDuration(elapsedVec) << std::endl;
	std::cout << "Time to process a range of " << inputDeq_.size()
			<< " elements with std::deque : " << formatDuration(elapsedDeq) << std::endl;
}
