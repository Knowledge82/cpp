/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:06:22 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/05 17:24:40 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class	PhoneBook
{
private:
	Contact contacts[8];
	int	contactCount;
	int	oldestIndex;

public:
	PhoneBook();
	~PhoneBook();

	void	addContact();
	void	searchContact() const;
	void	displayContactList() const;
	void	displaySingleContact(int index) const;

	//Utils
	bool	getInputLine(const std::string& prompt, std::string& input) const;
	bool	isValidIndex(const std::string& input, int& index) const;
};

#endif
