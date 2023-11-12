/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:16:20 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/12 10:16:30 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	int values[5] = {1, 2, 3, 4, -1};
	std::vector<int> a(values, values+5);
	//c11 funciona da seguinte forma
	//std::vector<int> values = {1, 2, 3, 4, 5};

	std::cout << "Size = " << a.size() << ", Capacity = " << a.capacity() << std::endl;
	std::cout << "Max size = " << a.max_size() << std::endl;
	a.push_back(6);
	std::cout << "After push back: size = " << a.size() << ", capacity = " << a.capacity() << std::endl;
	
	std::cout << "Print value on index 3 with a[3] = " << a[3] << " and with a.at(3)= " << a.at(3) << std::endl;
	std::cout << "Front = " << a.front() << " and back = " << a.back() << std::endl;
	a.insert(a.begin() + 2, -10);
	std::cout << "Insert a new value = 10 on the index 2. The value is " << a[2] << std::endl;
	
	std::cout << "-------Pop back-------\n";
	std::cout << "Size = " << a.size() << " before pop back." << std::endl;
	a.pop_back();
	std::cout << "Size = " << a.size() << " after pop back." << std::endl;
	
	//std::vector<int>::iterator it_vector = easyfind(a, 2);
	try{
		easyfind(a, 2);
		easyfind(a, -10);
		easyfind(a, 100);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
