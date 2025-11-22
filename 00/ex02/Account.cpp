/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 12:13:10 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/07 18:26:48 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* local time-print function [YYYYMMDD_HHMMSS]
 *
 * struct tm
 * {
 * 	int	tm_sec; (0-60)
 * 	int	tm_min; (0-59)
 * 	int	tm_hour; (0-23)
 * 	int	tm_mday; (1-31)
 * 	int	tm_mon; (0-11)
 * 	int	tm_year; (from 1900)
 * };
 */

static void	displayTimestamp(void)
{
	std::time_t	now = std::time(NULL);
	std::tm*	ltm = std::localtime(&now);

	std::cout << "["
		<< 1900 + ltm->tm_year
		<< (ltm->tm_mon < 9 ? "0" : "") << 1 + ltm->tm_mon
		<< (ltm->tm_mday < 10 ? "0" : "") << ltm->tm_mday << "_"
		<< (ltm->tm_hour < 10 ? "0" : "") << ltm->tm_hour
		<< (ltm->tm_min < 10 ? "0" : "") << ltm->tm_min
		<< (ltm->tm_sec < 10 ? "0" : "") << ltm->tm_sec
		<< "] ";
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	
	_nbAccounts++;
	_totalAmount += initial_deposit;

	displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";created" << std::endl;
}

Account::~Account(void)
{
	displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";closed" << std::endl;
}

// makeDeposit()
void	Account::makeDeposit(int deposit)
{
	displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount;

	this->_amount += deposit;
	this->_nbDeposits++;

	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";deposit:" << deposit
		<< ";amount:" << this->_amount
		<< ";nb_deposits:" << this->_nbDeposits
		<< std::endl;
}

// makeWithdrawal()
bool	Account::makeWithdrawal(int withdrawal)
{
	displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";p_amount:" << this->_amount;

	if (withdrawal > this->_amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	this->_amount -= withdrawal;
	this->_nbWithdrawals++;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
		<< ";amount:" << this->_amount
		<< ";nb_withdrawals:" << this->_nbWithdrawals
		<< std::endl;
	
	return true;
}

// checkAmount()
int	Account::checkAmount(void) const
{
	return this->_amount;
}

// displayStatus()
void	Account::displayStatus(void) const
{
	displayTimestamp();
	std::cout << "index:" << this->_accountIndex
		<< ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits
		<< ";withdrawals:" << this->_nbWithdrawals
		<< std::endl;
}

// displayAccountsInfos()
void	Account::displayAccountsInfos(void)
{
	displayTimestamp();
	std::cout << "accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

// Getters
int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
