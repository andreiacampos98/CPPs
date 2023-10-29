/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:00:46 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 15:55:43 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <cstdlib> 
#include <time.h>
#include <exception>

class Base
{
	private:
	public:
		Base();
		virtual ~Base();
};

class A: public Base
{
	public:
		A();
		~A();
};

class B: public Base
{
	public:
		B();
		~B();
};

class C: public Base
{
	public:
		C();
		~C();
};

Base * generate(void);
void identify_from_pointer(Base* p);
void identify_from_reference(Base& p);

#endif
