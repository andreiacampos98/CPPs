/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:44:25 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/21 15:08:41 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("default"), _grade(150)
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
		std::cout << "Bureaucrat constructor named " << this->_name << " and grade equal to " << this->_grade << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error!" << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src._name)
{
	_grade = src._grade;
	std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
	{
		this->_grade = src._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destroyed." << std::endl;
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return(this->_grade);
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (_grade == 1)
			throw Bureaucrat::GradeTooHighException();
		_grade--;
		std::cout << "Bureaucrat named " << _name << " increment the grade (" << _grade << ")." << std::endl;
	}
	catch (std::exception& e)
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
		std::cout << "Bureaucrat named " << _name << " decrement the grade (" << _grade << ")." << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error!" << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& src)
{
	os << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return(os);
}

void Bureaucrat::signForm(AForm &A)
{
	try
	{
		if (A.getFormSigned() == true)
		{
			std::cout << A.getFormName() << ", form already signed " << std::endl;
		}
		else
		{
			A.beSigned(*this);
		}
	}
	catch(std::exception &e)
	{
		std::cout << _name << " couldn't sign " << A.getFormName() << " because "  << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getFormName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
