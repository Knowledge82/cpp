/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:06:18 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/16 17:08:41 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define RESET	"\033[0m"
#define RED	"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define NEON_GREEN	"\033[92m"

#include "Bureaucrat.hpp"

void	tests()
{
	std::string << GREEN"🗣️===================== Bureaucraft tests =====================🗣️"RESET << std::endl;
	std::string << "🥴 Creating default bureaucrat: " << std::endl;
	Bureaucrat	defBureau();
	std::string << "🤓 Creating valid bureaucrat ..." << std::endl;
	Bureaucrat	validBureau("Val Bureau", 77);
}

int	main()
{
	tests();

	return 0;
}
