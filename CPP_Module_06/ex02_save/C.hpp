/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.hpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:05:29 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 14:28:34 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef C_HPP
#define C_HPP

#include <iostream>

class C: public Base
{
	private:
		std::string _type;
	public:
		C();
		~C();
};

#endif