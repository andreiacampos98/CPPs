/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:16:52 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/03 21:39:04 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <bits/stdc++.h> 

class EasyFind
{
	public:
	
		class ValueNotFound:public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "The value wasn't found";
				}
		};
};

template<typename T>
void	easyfind(T& value1, int value2)
{
	std::sort(value1.begin(), value1.end());
	try
	{
		if (std::find(value1.begin(), value1.end(), value2) != value1.end()) 
			std::cout << "\nElement found in the array\n";
		else
			throw EasyFind::ValueNotFound();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}


/*containers
   - sequence:
		- vector: elements are stored contiguously, have a dynamic size array, 
		usually occupy more space than static arrays because more memory is allocated to handle future growth;
		- stack: ;
		- queue;
		- list: double linked list (next and previous pointer);
		- deque: double ended queue (push and pop functions to move);
		- std::array;
		- containers adaptors: interfaces that implement special functionality on top of sequence containers;
	- associative:
		- Ordered (set: model of mathematical set: {x1, x2, x3, x4}, collection , map: set of pairs, multimap, multiset);
		- Unordered (nao sei);*/
