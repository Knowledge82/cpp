/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 12:26:21 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/03/16 13:59:01 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype> //std::isdigit()

RPN::RPN()
{

}

RPN::RPN(const RPN& other)
{
	(void)other;
}

RPN& RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
	}
	return *this;	
}

RPN::~RPN()
{

}

int	RPN::calculate(char op, int left, int right)
{
	if (op == '/' && right == 0)
		throw std::runtime_error("Error");
	
	switch (op)
	{
		case '+':
			return (left + right);
		case '-':
			return (left - right);
		case '*':
			return (left * right);
		case '/':
			return (left / right);
		default:
			throw std::runtime_error("Error");
	}
}

int	RPN::evaluate(const std::string& input)
{
	std::stack<int> 	st;	// push() - add to top, pop() - del from top, top() - look on top
	std::istringstream	ss(input);
	std::string			token;

	while (ss >> token)
	{
		if (token.size() == 1 && std::isdigit(static_cast<unsigned char>(token[0])))
			st.push(token[0] - '0');
		else if (token.size() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
		{
			if (st.size() < 2)
				throw std::runtime_error("Error");
			int right = st.top();
			st.pop();
			int left = st.top();
			st.pop();
			int	res = calculate(token[0], left, right);
			st.push(res);
		}
		else
			throw std::runtime_error("Error");
	}
	if (st.size() != 1)
		throw std::runtime_error("Error");
	return st.top();
}
