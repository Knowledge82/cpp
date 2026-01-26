#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Colors.hpp"
#include <stdexcept>

template <typename T>
Array<T>::Array() : data_(NULL), size_(0)
{
	std::cout << MAGENTA << "* Default constructor called *" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : data_(NULL), size_(n)
{
	std::cout << MAGENTA << "* Constructor with size called *" << RESET << std::endl;
	if (size_ > 0)
	{
		data_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++)
			data_[i] = T(); //explicit initialization. For int: int x = int() -> x == 0, etc
	}
}

template <typename T>
Array<T>::Array(const Array& other) : data_(NULL), size_(other.size_)
{
	std::cout << MAGENTA << "* Copy constructor called *" << RESET << std::endl;
	if (size_ > 0)
	{
		data_ = new T[size_];
		for (unsigned int i = 0; i < size_; i++)
			data_[i] = other.data_[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	std::cout << MAGENTA << "* Assignment operator called *" << RESET << std::endl;
	if (this != &other)
	{
		delete[] data_; // free old memory

		size_ = other.size_;
		data_ = NULL;

		if (size_ > 0)
		{
			data_ = new T[size_];
			for (unsigned int i = 0; i < size_; i++)
				data_[i] = other.data_[i];
		}
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= size_)
		throw std::out_of_range("Index out of bounds");
	return data_[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index >= size_)
		throw std::out_of_range("Index out of bounds");
	return data_[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return size_;
}

template <typename T>
Array<T>::~Array()
{
	std::cout << MAGENTA << "* Destructor called *" << RESET << std::endl;
	delete[] data_;
}

#endif
