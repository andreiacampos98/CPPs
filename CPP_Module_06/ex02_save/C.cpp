/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:05:34 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 15:02:24 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

C::C(): _type("C")
{
	std::cout << "C default constructor called." << std::endl;
}

C::~C()
{
	std::cout << "C destroyed." << std::endl;
}