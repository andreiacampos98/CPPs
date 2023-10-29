/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:10:53 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 11:51:52 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructor created." << std::endl;
}

Serializer::Serializer(const Serializer &src)
{
	(void)src;
	std::cout << "Serializer copy constructor called." << std::endl;
}

Serializer  &Serializer::operator=(const Serializer &src)
{
	(void)src;
	std::cout << "Serializer assignment operator overload called." << std::endl;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer destroyed." << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
