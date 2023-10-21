/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:36:41 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/21 14:09:46 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _signed(0), _grade(150), _reqGrade(150)
{
	std::cout << "Default Form constructor created." << std::endl;
}

Form::~Form()
{
	std::cout << "Form destroyed." << std::endl;
}

Form::Form(const std::string name, int grade, int reqGrade): _name(name), _grade(grade), _reqGrade(reqGrade)
{
	std::cout << "Form named " << _name << " constructor created with required grade to sign equal to " << _grade << " and the required grade to execute is " << _reqGrade <<  "." << std::endl;
	if (grade > 150 || reqGrade > 150)
	{
		throw Form::GradeTooLowException();
	}
	else if (grade < 1 || reqGrade < 1)
	{
		throw Form::GradeTooHighException();
	}
	this->_signed = false;
}

Form::Form(Form const &src): _name(src._name), _signed(src._signed), _grade(src._grade), _reqGrade(src._reqGrade)
{
	std::cout << "Copy constructor." << std::endl;
}

Form &Form::operator=(Form const &src)
{
	std::cout << "Copy assignment operator constructor." << std::endl;
	if (this != &src)
	{
		this->_signed = src._signed;
	}
	return (*this);
}

std::string Form::getFormName(void) const
{
	return(this->_name);
}

bool		Form::getFormSigned(void) const
{
	return(this->_signed);
}

int			Form::getFormGrade(void) const
{
	return(this->_grade);
}

int			Form::getFormReqGrade(void) const
{
	return(this->_reqGrade);
}

void		Form::beSigned(Bureaucrat const &Bur)
{
	try
	{
		if (Bur.getGrade() > this->_grade)
		{
			throw Form::GradeTooLowException();
		}
		else
		{
			this->_signed = true;
			std::cout << Bur.getName() << " signed " << _name << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& os, Form const& src)
{
	os << "Information for form " << src.getFormName() << std::endl;
	os << "Form's name: " << src.getFormName() << std::endl;
	os << "Is signed?: " << src.getFormSigned() << std::endl;
	os << "Grade required to sign: " << src.getFormGrade() << std::endl;
	os << "Grade required to execute: " << src.getFormReqGrade() << std::endl;
	return (os);
}
