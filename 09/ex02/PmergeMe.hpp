/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:11:43 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/21 18:27:49 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>

class	PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	void	run(int argc, char **argv);

private:
	struct				Pair
	{
		int	winner;
		int	loser;

		Pair(int a, int b) : winner(a >= b ? a : b), loser(a >= b ? b : a) {}
	};

	std::vector<int>	inputVec_;
	std::deque<int>		inputDeq_;
	
	static long long			nowMicroseconds();
	static int					parsePositiveIntStrict(const std::string& s);
	static std::vector<int>		parseToVector(int argc, char **argv);
	static std::deque<int>		parseToDeque(int argc, char **argv);
	static void					printSequence(const std::vector<int>& seq);
	static std::vector<size_t>	jacobshtalInsertionOrder(std::size_t n);

	static std::vector<int>		fordJohnsonVector(const std::vector<int>& input);
	static std::deque<int>		fordJohnsonDeque(const std::deque<int>& input);

	static bool isSorted(const std::vector<int>& v);
	static bool isSorted(const std::deque<int>& d);
};

#endif
