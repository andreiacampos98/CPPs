/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 14:00:25 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 16:25:02 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::Base()
{
	std::cout << "Base default constructor called." << std::endl;
}

Base::~Base()
{
	std::cout << "Base destroyed." << std::endl;
}

A::A()
{
	std::cout << "A default constructor called." << std::endl;
}

A::~A()
{
	std::cout << "A destroyed." << std::endl;
}

B::B()
{
	std::cout << "B default constructor called." << std::endl;
}

B::~B()
{
	std::cout << "B destroyed." << std::endl;
}

C::C()
{
	std::cout << "C default constructor called." << std::endl;
}

C::~C()
{
	std::cout << "C destroyed." << std::endl;
}


Base * generate(void)
{
	int	randomNb;

	srand(time(0)); 
  	randomNb = (rand() % 3) + 1;
	if (randomNb == 1)
		return static_cast<Base *> (new A());
	else if (randomNb == 2)
		return static_cast<Base *> (new B());
	else
		return static_cast<Base *> (new C());
}

void identify_from_pointer(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
	else
		std::cout << "It isn't possible to identify the type." << std::endl; 
}

void identify_from_reference(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
