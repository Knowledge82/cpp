/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdarsuye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:18:06 by vdarsuye          #+#    #+#             */
/*   Updated: 2026/01/16 11:06:26 by vdarsuye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void	iter(T* array, const size_t length, F func)
{
	if (!array || length == 0)
		return;
	for (size_t i = 0; i < length; i++)
		func(array[i]);
}

/* another way:
 *
 * NON CONST
 * template <typename T>
 * void	iter(T* array, const size_t length, (*func)(T&)
 * {
 *	for (size_t i = 0; i < length - 1; i++)
 *		func(array[i]);
 * }
 *
 * CONST
 * template <typename T>
 * void	iter(const T* array, const size_t length, (*func)(const T&)
 * {
 *	for (size_t i = 0; i < length - 1; i++)
 *		func(array[i]);
 * }
 */

#endif
