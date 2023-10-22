/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:43:50 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/22 14:04:48 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main()
{
	std::cout << "\n....................................................\n";
	std::cout << "PresidentialPardonForm" << std::endl;
	std::cout << "....................................................\n";
	Intern Andreia;
	Bureaucrat Filipa("Filipa", 5);
	{
		AForm* a;
		AForm* b;
		a = Andreia.makeForm("Presidential Pardon", "target");
		b = new PresidentialPardonForm("target1");

		std::cout << "\nTest: Execute form but Not signed\n";
		Filipa.executeForm(*a);
		Filipa.executeForm(*b);
			
		std::cout << "\nTest: Execute form but Grade lower\n";
		Filipa.signForm(*a);
		Filipa.executeForm(*a);
		Filipa.signForm(*b);
		Filipa.executeForm(*b);
			
		std::cout << "\nTest: Execute Form\n";
		Filipa.incrementGrade();
		Filipa.executeForm(*a);
		Filipa.executeForm(*b);

		delete a;
		delete b;
	}
	std::cout << "\n....................................................\n";
	std::cout << "RobotomyRequestForm" << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Filipa1("Filipa1", 46);
	{
		AForm* a;
		AForm* b;
		a = Andreia.makeForm("Robotomy Request", "target");
		b = new RobotomyRequestForm("target1");

		std::cout << "\nTest: Execute form but Not signed\n";
		Filipa1.executeForm(*a);
		Filipa1.executeForm(*b);
			
		std::cout << "\nTest: Execute form but Grade lower\n";
		Filipa1.signForm(*a);
		Filipa1.executeForm(*a);
		Filipa1.signForm(*b);
		Filipa1.executeForm(*b);
			
		std::cout << "\nTest: Execute Form\n";
		Filipa1.incrementGrade();
		Filipa1.executeForm(*a);
		Filipa1.executeForm(*b);

		delete a;
		delete b;
	}
	std::cout << "\n....................................................\n";
	std::cout << "ShrubberyCreationForm" << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Filipa2("Filipa2", 138);
	{
		AForm* a;
		AForm* b;
		a = Andreia.makeForm("Shrubbery Creation", "target");
		b = new ShrubberyCreationForm("target1");

		std::cout << "\nTest: Execute form but Not signed\n";
		Filipa2.executeForm(*a);
		Filipa2.executeForm(*b);
			
		std::cout << "\nTest: Execute form but Grade lower\n";
		Filipa2.signForm(*a);
		Filipa2.executeForm(*a);
		Filipa2.signForm(*b);
		Filipa2.executeForm(*b);
			
		std::cout << "\nTest: Execute Form\n";
		Filipa2.incrementGrade();
		Filipa2.executeForm(*a);
		Filipa2.executeForm(*b);

		delete a;
		delete b;
	}
	std::cout << "\n....................................................\n";
	std::cout << "Form doesn't exist" << std::endl;
	std::cout << "....................................................\n";
	Bureaucrat Filipa3("Filipa3", 5);
	{
		try
		{
			AForm* a;
			AForm* b;
			a = Andreia.makeForm("Presidential", "target");
			b = Andreia.makeForm("One more", "target");

			std::cout << "\nTest: Execute form but Not signed\n";
			Filipa3.executeForm(*a);
			Filipa3.executeForm(*b);
				
			std::cout << "\nTest: Execute form but Grade lower\n";
			Filipa3.signForm(*a);
			Filipa3.executeForm(*a);
			Filipa3.signForm(*b);
			Filipa3.executeForm(*b);
				
			std::cout << "\nTest: Execute Form\n";
			Filipa3.incrementGrade();
			Filipa3.executeForm(*a);
			Filipa3.executeForm(*b);

			delete a;
			delete b;
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	
	}
}
