#include "easyfind.hpp"
#include "Colors.hpp"
#include <vector>
#include <list>
#include <iostream>

int	main()
{
	std::cout << GREEN << "\n=================== TESTS =====================\n" << RESET << std::endl;

	std::cout << "--- vector<int> ---" << std::endl;
	std::vector<int>	vec;
	vec.push_back(69);
	
	try
	{
		std::vector<int>::const_iterator vec_it;
		
		std::cout << "Valid case:" << std::endl;
		vec_it = easyfind(vec, 69);
		std::cout << *vec_it << std::endl;

		std::cout << std::endl;

		std::cout << "Invalid case:" << std::endl;
		vec_it = easyfind(vec, 42);
		std::cout << *vec_it << std::endl;
	}
	catch(const std::out_of_range& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}
	
	std::cout << std::endl;
	
	std::cout << "--- list<int> ---" << std::endl;
	std::list<int>		lst;
	lst.push_back(69);

	try
	{
		std::list<int>::const_iterator lst_it;
		
		std::cout << "Valid case:" << std::endl;
		lst_it = easyfind(lst, 69);
		std::cout << *lst_it << std::endl;

		std::cout << std::endl;

		std::cout << "Invalid case:" << std::endl;
		lst_it = easyfind(lst, 42);
		std::cout << *lst_it << std::endl;
	}

	catch(const std::out_of_range& e)
	{
		std::cerr << YELLOW << e.what() << RESET << std::endl;
	}

	std::cout << GREEN << "\n=================== END OF TESTS =====================\n" << RESET << std::endl;
	return 0;
}

