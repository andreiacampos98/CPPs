/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:16:52 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/02 21:29:58 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>

template<typename T>
void	easyfind(T value1, int value2)
{
	(void)value1;
	(void)value2;
}


template <typename T>
void showVector(string vName, const vector<T> &v)
{
	std::cout << vName << "[] = { ";
	for (vector<T>::const_iterator vPtr = v.begin(); vPtr != v.end(); vPtr++)
	std::cout << *vPtr << " ";
	std::cout << "}\n";
}

/*containers
   - sequence:
		- vector; dynamic size array;
		- stack: ;
		- queue;
		- list: double linked list (next and previous pointer);
		- deque: double ended queue (push and pop functions to move);
		- std::array;
		- containers adaptors: interfaces that implement special functionality on top of sequence containers;
	- associative:
		- Ordered (set: model of mathematical set: {x1, x2, x3, x4}, collection , map: set of pairs, multimap, multiset);
		- Unordered ();*/