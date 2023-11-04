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


/* Components of STL: containers, iterators, algorithm and functors
containers - are just array like data structures that store the collection of objects;
Containers are object that handle a collection of other objects (elements) implementing a well defined structure.
   - sequence:
		- vector: elements are stored contiguously, have a dynamic size array, 
		usually occupy more space than static arrays because more memory is allocated to handle future growth;
		- std::array;
		- list: double linked list (next and previous pointer);
		- deque: double ended queue (push and pop functions to move);
		- stack: ;
		- queue: use FIFO when we do push and pop;
		- containers adaptors: interfaces that implement special functionality on top of sequence containers;
	- associative:
		- Ordered (set: model of mathematical set: {x1, x2, x3, x4}, collection , map: set of pairs, multimap, multiset);
		- Unordered (nao sei);
  
  Iterators are objects that enable traversal of containers in some order, for either reading or writing.
  Iterators are defined as templates and must comply with a very specific set of rules in order to qualify as one of many types of iterators.
  Pointers are a particular type of integers.
  Types of iterators:
  	- input: only able to read, only moves forward (++it ot it++)
   	- output: only able to write, only moves forward
    	- forward: it has the features of input and output, 
     	- Bidirectional: all features of forward iterators and it is possible to move backward;
      	- Random-Access: all features for bidirectional and it is possible to acess a specific index
       */
