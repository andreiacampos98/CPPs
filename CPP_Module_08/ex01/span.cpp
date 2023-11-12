/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:43:40 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/12 12:46:12 by anaraujo         ###   ########.fr       */
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
	_values.clear();
	_values=src._values;
	std::cout << "Copy constructor." << std::endl;
}

Span &Span::operator=(Span const &src)
{
	_N=src._N;
	_values=src._values;
	std::cout << "Copy assignment." << std::endl;
	return(*this);
}

Span::~Span()
{
	std::cout << "Destroyed." << std::endl;
}

void	Span::addNumber(int value)
{
	if (_values.size() >= _N)
		throw Span::SpanFull();
	_values.push_back(value);
}

void Span::addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end)
{
	int range = std::distance(begin, end);
	if (range + _values.size() > _N )
	{
		_values.insert(_values.end(), begin, begin + (this->_N - this->_values.size()));
		throw Span::SpanFull();
	}
	else
		_values.insert(_values.end(), begin, end);
}

long int	Span::longestSpan()
{
	long max;
	if (_values.size() < 2)
		throw Span::SpanOneOrLessNumbers();
	max = std::abs((long)*std::max_element(_values.begin(), _values.end()) - (long)*std::min_element(_values.begin(), _values.end()));
	return (max);
}

long int	Span::shortestSpan()
{
	long int min = Span::longestSpan();
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
				if (std::abs((long)*ptr - (long)*ptr1) < min)
					min = std::abs((long)*ptr - (long)*ptr1);
			}
		}
	}
	return (min);
}

void	Span::print_vector()
{
	for (unsigned int i = 0; i < _values.size(); i++)
		std::cout << "Span[" << i << "] = " << _values[i] << std::endl;
	std::cout << "Size = " << _N << std::endl;
}
