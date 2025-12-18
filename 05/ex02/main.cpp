/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 17:06:18 by vdarsuye          #+#    #+#             */
/*   Updated: 2025/12/18 15:31:31 by vdarsuye         ###   ########.fr       */
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
#include "Form.hpp"
#include <iostream>

void	tests()
{
	std::cout << GREEN"\n===================== Form tests =====================\n"RESET << std::endl;
	std::cout << GREEN"\n===== Creating bureaucrats for testing forms =====\n"RESET << std::endl;
	std::cout << "🥴 Creating low grade bureaucrat: " << std::endl;
	Bureaucrat	badBureau("lowOne", 150);
	std::cout << badBureau << std::endl;
	std::cout << "----------------------\n" << std::endl;
	
	std::cout << "🤩 Creating high grade bureaucrat: " << std::endl;
	Bureaucrat	goodBureau("goodOne", 1);
	std::cout << goodBureau << std::endl;
	std::cout << "----------------------\n" << std::endl;

	
	std::cout << GREEN"\n===== Creating forms =====\n"RESET << std::endl;
	// invalid too low form
	std::cout << "❌📝Creating invalid form (\"\", 666, 100) " << std::endl;
	try
	{
		Form	invalidForm("", 666, 100);
		std::cout << invalidForm << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}

	// invalid to high zero form
	std::cout << "❌0️⃣ 📝Creating invalid form (Zero, 0, 100) " << std::endl;
	try
	{
		Form	zeroForm("Zero", 0, 100);
		std::cout << zeroForm << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}

	// valid medium grade form
	std::cout << "✅📝Creating valid medium grade form in try/catch block: " << std::endl;
	try
	{
		Form	mediumForm("MediumGradeForm", 42, 42);
		std::cout << mediumForm << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		std::cout << "----------------------\n" << std::endl;
	}
	
	// valid high grade form
	std::cout << "🌟📜🌟 Creating high grade form: " << std::endl;
	Form	highForm("HighGradeForm", 3, 2);
	std::cout << highForm << std::endl;
	std::cout << "----------------------\n" << std::endl;
	
	// valid low grade form
	std::cout << "📝 Creating low grade form: " << std::endl;
	Form	lowForm("LowGradeForm", 142, 42);
	std::cout << lowForm << std::endl;
	std::cout << "----------------------\n" << std::endl;
	
	std::cout << GREEN"\n===== signForm test =====\n"RESET << std::endl;
	// success case
	std::cout << "🟢Success case: ";
	goodBureau.signForm(highForm);
	std::cout << std::endl;
	// fail case
	std::cout << "🔴Fail case: ";
	badBureau.signForm(lowForm);
	std::cout << std::endl;
	
	// case of sign already signed form
	std::cout << "🟠Signing already signed form case: " << std::endl;
	std::cout << std::endl;
	goodBureau.signForm(highForm);
	goodBureau.signForm(lowForm);
	goodBureau.signForm(lowForm);
	std::cout << std::endl;
	
	

	std::cout << GREEN"\n===================== End of tests() =====================\n"RESET << std::endl;
}

int	main()
{
	tests();

	std::cout << GREEN"\n===================== End of main() =====================\n"RESET << std::endl;
	return 0;
}
