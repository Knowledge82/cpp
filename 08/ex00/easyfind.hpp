#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template <typename T>
typename T::const_iterator	easyfind(const T& container, int n)
{
	typename T::const_iterator it = std::find(container.begin(), container.end(), n);

	if (it == container.end())
		throw std::out_of_range("Element not found");
	return *it;
}

#endif
