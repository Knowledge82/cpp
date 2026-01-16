/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 15:37:25 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/16 17:28:19 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class	Array
{
public:
	Array() : data_(NULL), size_(0)
	{

	}

	Array(unsigned int n) : data_(NULL), size_(0)
	{
		if (n > 0)
		{
			data_ = new T[n];
			for (int i = 0; i < n; i++)
				data_[i] = T(); // default init
		}
	}

	Array(const Array& other) : data_(NULL), size_(other.size_)
	{
		if (size_ > 0)
		{
			data_ = new T[size_];
			for (int i = 0; i < size_; i++)
				data_[i] = other.data_[i];
		}
	}

	Array& operator=(const Array& other)
	{

	}

	~Array()
	{
		delete[] data_;
	}

private:
	T*		data_;
	unsigned int	size_;
};

#endif
