/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:11:43 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/19 18:13:08 by vdarsuye         ###   ########.fr       */
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

	void	parseInput(int argc, char **argv);
	void	sortAndDisplay();

private:
	struct				Pair
	{
		int	winner;
		int	loser;

		Pair(int a, int b) : winner(a >= b ? a : b), loser(a >= b ? b : a) {}
	};

	std::vector<int>	vec_;
	std::deque<int>		deq_;
	
	static int	parsePositiveIntStrict(const std::string& s);
	static void	buildPairsVector(const std::vector<int>& in, std::vector<Pair>& pairs,
								bool& hasStraggler, int& straggler);
	static void	extractWinners(const std::vector<Pair>& pairs, std::vector<int>& winners);

	void	sortVector();
	void	sortDeque();
};

#endif
