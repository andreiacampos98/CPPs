/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:43:50 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/21 14:11:21 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main()
{
	
	std::cout << "\n....................................................\n";
	std::cout << "Grade required to sign is lower than the Bureaucrat's grade." << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Andreia("Andreia", 2);
	std::cout << Andreia;
	{
		try
		{
			Form A("FormAndreia", 30, 40);
			std::cout << "..............................\n";
			std::cout << A;
			std::cout << "..............................\n";
			A.beSigned(Andreia);
			std::cout << "..............................\n";
			std::cout << A;
			std::cout << "..............................\n";
			Andreia.signForm(A);
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << "\n....................................................\n";
	std::cout << "Grade required to sign is higher than the Bureaucrat's grade." << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Andreia1("Andreia1", 51);
	std::cout << Andreia1;
	{
		try
		{
			Form A("FormAndreia1", 50, 40);
			std::cout << "..............................\n";
			std::cout << A;
			std::cout << "..............................\n";
			A.beSigned(Andreia1);
			Andreia1.signForm(A);
			std::cout << "..............................\n";
			std::cout << A;
			std::cout << "..............................\n";
		}
		catch (std::exception &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << "\n....................................................\n";
	std::cout << "Grade is higher than 150." << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Andreia2("Andreia2", 20);
	std::cout << Andreia2;
	{	
		try
		{
			Form B("FormB", 180, 40);
			B.beSigned(Andreia2);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << "\n....................................................\n";
	std::cout << "Grade required is higher than 150." << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Andreia3("Andreia3", 20);
	std::cout << Andreia3;
	{	
		try
		{
			Form C("FormC", 30, 180);
			C.beSigned(Andreia3);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << "\n....................................................\n";
	std::cout << "Grade is lower than 1." << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Andreia4("Andreia4", 20);
	std::cout << Andreia4;
	{	
		try
		{
			Form B("FormB", 1, 40);
			B.beSigned(Andreia4);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	std::cout << "\n....................................................\n";
	std::cout << "Grade required is lower than 1." << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Andreia5("Andreia5", 20);
	std::cout << Andreia5;
	{	
		try
		{
			Form C("FormC", 30, 0);
			C.beSigned(Andreia5);
		}
		catch (Form::GradeTooHighException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
		catch (Form::GradeTooLowException &e)
		{
			std::cout << "Error!" << e.what() << std::endl;
		}
	}
	return (0);
}
