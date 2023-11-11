/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:43:40 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/11 00:33:53 by anaraujo         ###   ########.fr       */
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

long int	Span::longestSpan()
{
	long int max;
	try
	{
		if (_values.size() < 2)
			throw Span::SpanOneOrLessNumbers();
		max = std::abs(*std::max_element(_values.begin(), _values.end()) - *std::min_element(_values.begin(), _values.end())) ;
		std::cout << "ola " << *std::min_element(_values.begin(), _values.end()) << std::endl;
		std::cout << *std::max_element(_values.begin(), _values.end());
		return (max);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}

long int	Span::shortestSpan()
{
	long int min = Span::longestSpan();
	try
	{
		if (_values.size() < 2)
			throw Span::SpanOneOrLessNumbers();
		else
		{
			for (std::vector<int>::iterator ptr = _values.begin(); ptr < _values.end(); ptr++)
			{
				for (std::vector<int>::iterator ptr1 = _values.begin(); ptr1 < _values.end(); ptr1++)
				{
					if (ptr == ptr1)
						continue;
					if (std::abs(*ptr - *ptr1) < min)
						min = std::abs(*ptr - *ptr1);			
				}
			}
		}
		return (min);
		
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (min);
}

void	Span::print_vector()
{
	for (unsigned int i = 0; i < _values.size(); i++)
		std::cout << "Span[" << i << "] = " << _values[i] << std::endl;
}
