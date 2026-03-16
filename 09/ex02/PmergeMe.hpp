/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:11:43 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/16 17:45:03 by vdarsuye         ###   ########.fr       */
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
	std::vector<int>	vec_;
	std::deque<int>		deq_;

	static int	parsePositiveIntStrict(const std::string& s);
	void	sortVector();
	void	sortDeque();
	
};

#endif
