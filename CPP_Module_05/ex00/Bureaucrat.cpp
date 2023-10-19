/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:44:25 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/19 18:59:17 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(): _name("default"), _grade(1)
{
	std::cout << "Default Bureaucrat constructor." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	try
	{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		_grade = grade;
		std::cout << "Bureaucrat constructor named " << this->_name << " and grade equal to " << this->_grade << std::endl
	}
	catch (std::exception &e)
	{
		std::cerr << "Error!" << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{

}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyed." << std::endl;
}

std::string Bureaucrat::getName(void)
{
	return (this->_name);
}

std::int Bureaucrat::getGrade(void)
{
	return(this->_grade);
}

void Bureaucrat::incrementGrade(Bureaucrat bur)
{
	try
	{
		if (_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		_grade--;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error!" << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (_grade == 150)
			throw Bureaucrat::GradeTooLowException();
		_grade++;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error!" << e.what() << std::endl;
	}
}

void	Bureaucrat::GradeTooHighException(void)
{
	std::cout << "Grade too high" << std::endl;
}

void	Bureaucrat::GradeTooLowException(void)
{
	std::cout << "Grade too low" << std::endl;
}