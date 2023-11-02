/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:16:20 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/02 20:41:44 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	int a[5] = {1, 2, 3, 4, 5};
	std::vector<int> values(a, a+5);
	//c11 funciona da seguinte forma
	//td::vector<int> values = {1, 2, 3, 4, 5};
	
	for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
	{
		std::cout << *it << std::endl;
	}
}
