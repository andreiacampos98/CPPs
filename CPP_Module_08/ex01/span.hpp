/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:43:07 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/12 11:41:56 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

class Span
{
	private:
		unsigned int 	_N;
		std::vector<int> _values;
		Span();
	public:
		Span(unsigned int N);
		Span(Span const &src);
		Span &operator=(Span const &src);
		~Span();

		void addNumber(int value);
		void addNumber(const std::vector<int>::iterator& begin, const std::vector<int>::iterator& end);
		long int shortestSpan();
		long int longestSpan();
		void print_vector();

	class SpanFull: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Span is full.";
			}
	};
	
	class SpanOneOrLessNumbers: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Span with one or less numbers.";
			}
	};
};

#endif
