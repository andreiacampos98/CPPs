/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:55:35 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/31 21:52:22 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template<typename T>
void	iter(T *array, int N, void (*f)(const T& array))
{
	for (int i = 0; i < N; i++)
	{
		f(array[i]);
	}
}

template<typename T>
void print( T &x )
{
  std::cout << x << std::endl;
  return;
}
