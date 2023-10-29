/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:10:51 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 11:52:59 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data		*ptr;
	Data		*new_ptr;
	uintptr_t	raw;

	ptr = new Data;
	ptr->name = "Andreia";
	ptr->age = 13;
	
	raw = Serializer::serialize (ptr);
	
	new_ptr = Serializer::deserialize(raw);

	std::cout << "Data of ptr: name = " << ptr->name << ", age = " << ptr->age << std::endl;
	std::cout << "Data of new_ptr: name = " << new_ptr->name << ", age = " << new_ptr->age << std::endl;
	delete ptr;
}
