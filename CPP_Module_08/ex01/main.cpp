/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 21:44:10 by anaraujo          #+#    #+#             */
/*   Updated: 2023/11/11 00:30:34 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	sp.print_vector();
	std::cout << "Test exception\n";
	sp.addNumber(30);
	sp.addNumber(11);


	std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp.longestSpan()<< std::endl;
	
	Span sp1 = Span(1);
	std::cout << "Shortest span: " << sp1.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp1.longestSpan()<< std::endl;

	Span sp2 = Span(20);
	sp2.addNumber(147483648);
	sp2.addNumber(2147483647);
	sp2.addNumber(-2147483648);
	sp2.addNumber(147483648);
	sp2.print_vector();
	std::cout << "Shortest span: " << sp2.shortestSpan() << std::endl;
	std::cout << "Longest span: " << sp2.longestSpan()<< std::endl;
	//std::cout << sp.shortestSpan() << std::endl;
	//std::cout << sp.longestSpan() << std::endl;

	return 0;
}
