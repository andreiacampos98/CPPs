/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:43:50 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/20 20:26:30 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	
	Bureaucrat Andreia("Andreia", 2);
	std::cout << Andreia;
	Andreia.incrementGrade();
	Andreia.incrementGrade();
	
	Bureaucrat Teste("Teste", 149);
	std::cout << Teste;
	Teste.decrementGrade();
	std::cout << Teste;
	Teste.decrementGrade();

	Bureaucrat Teste1("Teste1", 200);
	std::cout << Teste1;
	return (0);
}
