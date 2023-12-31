/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 18:57:14 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/01 11:05:35 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
template<typename T> // tell the compiler that we're writing a template
void	swap(T &value1 , T &value2)
{
	T tmp;
	tmp = value2;
	value2 = value1;
	value1 = tmp;
}

template<typename T>
T	min(T value1, T value2)
{
	if (value1 < value2)
		return (value1);
	else if (value1 > value2)
		return (value2);
	else
		return (value2);
}

template<typename T>
T	max(T value1, T value2)
{
	if (value1 < value2)
		return (value2);
	else if (value1 > value2)
		return (value1);
	else
		return (value2);
}
