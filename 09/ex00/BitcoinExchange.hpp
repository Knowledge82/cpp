/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 12:49:24 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/09 13:02:24 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include "Colors.hpp"

class	BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void	loadDB(const std::string& filename);
	void	processInput(const std::string& filename);

private:
	std::map<std::string, double>	db_;
	bool							isValidDate(const std::string& date) const;
	bool							isValidValue(const std::string& value, double& out) const;
	double							getRate(const std::string& date) const;

};

#endif
