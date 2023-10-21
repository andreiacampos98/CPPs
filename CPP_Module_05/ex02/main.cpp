/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:43:50 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/21 21:14:34 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main()
{
	
	//B = new AForm("FormAndreia", 30, 40);
	//B.besigned(teste);
	
	std::cout << "\n....................................................\n";
	std::cout << "PresidentialPardonForm" << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Andreia("Andreia", 5);
	std::cout << Andreia;
	AForm *A = new PresidentialPardonForm("target");
	{
		try
		{
			std::cout << "\nTest: Execute form but Not signed\n";
			Andreia.executeForm(*A);
			
			std::cout << "\nTest: Execute form but Grade lower\n";
			Andreia.signForm(*A);
			Andreia.executeForm(*A);
			
			std::cout << "\nTest: Execute Form\n";
			Andreia.incrementGrade();
			Andreia.executeForm(*A);
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << "\n....................................................\n";
	std::cout << "RobotomyRequestForm" << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Andreia1("Andreia1", 46);
	std::cout << Andreia1;
	AForm *B = new RobotomyRequestForm();
	{
		try
		{
			std::cout << "\nTest: Execute form but Not signed\n";
			Andreia1.executeForm(*B);
			
			std::cout << "\nTest: Execute form but Grade lower\n";
			Andreia1.signForm(*B);
			Andreia1.executeForm(*B);
			
			std::cout << "\nTest: Execute Form\n";
			Andreia1.incrementGrade();
			Andreia1.executeForm(*B);
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << "\n....................................................\n";
	std::cout << "ShrubberyCreationForm" << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Andreia2("Andreia2", 138);
	std::cout << Andreia2;
	AForm *C = new ShrubberyCreationForm();
	{
		try
		{
			std::cout << "\nTest: Execute form but Not signed\n";
			Andreia2.executeForm(*C);
			
			std::cout << "\nTest: Execute form but Grade lower\n";
			Andreia2.signForm(*C);
			Andreia2.executeForm(*C);
			
			std::cout << "\nTest: Execute Form\n";
			Andreia2.incrementGrade();
			Andreia2.executeForm(*C);
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	delete A;
	delete B;
	delete C;
}
