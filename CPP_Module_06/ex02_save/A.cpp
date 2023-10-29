/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:05:34 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 14:20:28 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"

A::A(): _type("A")
{
	std::cout << "A default constructor called." << std::endl;
}

A::~A()
{
	std::cout << "A destroyed." << std::endl;
}
