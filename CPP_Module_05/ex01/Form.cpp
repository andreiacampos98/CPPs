/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:36:41 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/20 22:21:25 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("default"), _signed(0), _grade(150), _reqGrade(0)
{
	std::cout << "Default Form constructor created." << std::endl;
}

Form::~Form()
{
	std::cout << "Form destroyed." << std::endl;
}

Form::Form(std::string const name, bool s, int grade, int reqGrade): _name(name), _signed(s), _grade(grade), _reqGrade(reqGrade)
{
	std::cout << "Form named " << _name << "constructor created with grade " << _grade << " and the required grade is " << _reqGrade <<  "." << std::endl;
}

Form::Form(Form const &src)
{
	this->_name = src.getName();
	this->_grade = src._grade;
	this->_reqGrade = src._grade;
	this->_signed = src._signed;
	std::cout << "Copy constructor." << std::endl;
}

Form &Form::operator=(Form const &src)
{
	std::cout << "Copy assignment operator constructor." << std::endl;
	if (this != &src)
	{
		this->_name = src.getName();
		this->_grade = src._grade;
		this->_reqGrade = src._grade;
		this->_signed = src._signed;
	}
	return (*this);
}

std::string Form::getFormName(void)
{
	return(this->_name);
}

bool		Form::getFormSigned(void)
{
	return(this->_signed);
}

int			Form::getFormGrade(void)
{
	return(this->_grade);
}

int			Form::getFormReqGrade(void)
{
	return(this->_reqGrade);
}

void		Form::beSigned(Bureaucrat &Bur)
{
	if (Bur.getGrade < _reqGrade)
	{
		_signed = 1;
		
	}
	else
	{
		throw Form::GradeTooLowException;
	}
}
