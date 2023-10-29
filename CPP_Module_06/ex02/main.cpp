/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:07:17 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/29 15:55:17 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Base.hpp"

int main()
{
	Base *a;
	a = new A();
	identify_from_pointer(a);
	delete a;

	Base *b;
	b = new B();
	identify_from_pointer(b);
	delete b;

	Base *c;
	c = new C();
	identify_from_pointer(c);
	delete c;
	
	Base *base = generate();
	Base & baseRef = *base;

	identify_from_reference(baseRef);
	delete base;
}
