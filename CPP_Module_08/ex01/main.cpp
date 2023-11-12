/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:44:10 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/12 12:48:28 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "span.hpp"

int main()
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		sp.print_vector();
		std::cout << "\n----Testing add number when the span is full----\n";
		try
		{
			sp.addNumber(30);
			sp.addNumber(11);
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan()<< std::endl;
		std::cout << "\n----Testing calculate the shortest and longest span with only one value in the Span----\n";
		try
		{
			Span sp1 = Span(1);
			std::cout << "Shortest span, but the vector has only one number: " << sp1.shortestSpan() << std::endl;
			std::cout << "Longest span, but the vector has only one number: " << sp1.longestSpan()<< std::endl;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\n----Testing Span with min int and max int values-----\n";
		Span sp2 = Span(20);
		sp2.addNumber(2147483647);
		sp2.addNumber(-2147483648);
		sp2.print_vector();
		std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp2.longestSpan()<< std::endl;
	}
	{
		std::cout << "\n----Testing Span with 10000 values-----\n";
		Span sp3 = Span(10000);
		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
		{
			const int value = rand();
			sp3.addNumber(value);
		}
		std::cout << "Shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp3.longestSpan()<< std::endl;
	}
	{
		std::cout << "\n----Testing add number with a vector-----\n";
		Span test = Span(10000);
		test.addNumber(200000);
		std::vector<int> v1;
		srand(time(NULL));
		for (int i = 0; i < 10000; i++)
		{
			const int value = rand();
			v1.push_back(value);
		}
		try
		{
			test.addNumber(v1.begin(), v1.end());
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
		std::cout << "Longest span: " << test.longestSpan()<< std::endl;
	}
	{
		std::cout << "\n----Testing copies----\n";
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		
		Span sp1(sp);
		Span sp2(10);
		sp2.addNumber(-5);
		std::cout << "\nSP2 before =\n";
		sp2.print_vector();
		sp2 = sp;
		sp.addNumber(11);
		std::cout << "\nSP1\n";
		sp1.print_vector();
		std::cout << "\nSP2\n";
		sp2.print_vector();
		std::cout << "\nSP\n";
		sp.print_vector();
	}
	return 0;
}
