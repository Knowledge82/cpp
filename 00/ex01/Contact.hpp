/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:06:00 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/08/06 12:09:59 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class	Contact
{
private:
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;

public:
	Contact();
	~Contact();

	//Setters
	void	setFirstName(const std::string& name);
	void	setLastName(const std::string& name);
	void	setNickname(const std::string& name);
	void	setPhoneNumber(const std::string& number);
	void	setDarkestSecret(const std::string& secret);

	// Getters
	std::string	getFirstName() const;
	std::string	getLastName() const;
	std::string	getNickname() const;
	std::string	getPhoneNumber() const;
	std::string	getDarkestSecret() const;

	// Utils
	void	displayContact() const;
	std::string	truncateString(const std::string& str, size_t width) const;
};

#endif
