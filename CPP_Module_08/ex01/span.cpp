/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:43:40 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/04 00:20:09 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "span.hpp"

Span::Span()
{
	std::cout << "Default constructor created." << std::endl;
}

Span::Span(unsigned int N): _N(N)
{
	std::cout << "Constructor created with N = " << _N << std::endl;
}

Span::Span(Span const &src)
{
	_N=src._N;
	std::cout << "Copy constructor." << std::endl;
}

Span &Span::operator=(Span const &src)
{
	_N=src._N;
	std::cout << "Copy assignment." << std::endl;
	return(*this);
}

Span::~Span()
{
	std::cout << "Destroyed." << std::endl;
}

void	Span::addNumber(int value)
{
	try
	{
		if (_values.size() >= _N)
			throw Span::SpanFull();
		_values.push_back(value);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	Span::shortestSpan()
{
	try
	{
		if (_values.size() < 2)
			throw Span::SpanOneOrLessNumbers();
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	Span::longestSpan()
{
	try
	{
		std::sort(_values.begin(), _values.end());
		if (_values.size() < 2)
			throw Span::SpanOneOrLessNumbers();
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int	Span::print_vector()
{
	for (unsigned int i = 0; i < _values.size(); i++)
		std::cout << "Span[" << i << "] = " << _values[i] << std::endl;
}
