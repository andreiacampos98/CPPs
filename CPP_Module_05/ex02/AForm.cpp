/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:36:41 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/21 21:02:55 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("default"), _signed(0), _grade(150), _reqGrade(150)
{
	std::cout << "Default AForm constructor created." << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destroyed." << std::endl;
}

AForm::AForm(const std::string &name, int grade, int reqGrade): _name(name), _grade(grade), _reqGrade(reqGrade)
{
	std::cout << "AForm named " << _name << " constructor created with required grade to sign equal to " << _grade << " and the required grade to execute is " << _reqGrade <<  "." << std::endl;
	if (grade > 150 || reqGrade > 150)
	{
		throw AForm::GradeTooLowException();
	}
	else if (grade < 1 || reqGrade < 1)
	{
		throw AForm::GradeTooHighException();
	}
	this->_signed = false;
}

AForm::AForm(AForm const &src): _name(src._name), _signed(src._signed), _grade(src._grade), _reqGrade(src._reqGrade)
{
	std::cout << "Copy constructor." << std::endl;
}

AForm &AForm::operator=(AForm const &src)
{
	std::cout << "Copy assignment operator constructor." << std::endl;
	if (this != &src)
	{
		this->_signed = src._signed;
	}
	return (*this);
}

std::string AForm::getFormName(void) const
{
	return(this->_name);
}

bool		AForm::getFormSigned(void) const
{
	return(this->_signed);
}

int			AForm::getFormGrade(void) const
{
	return(this->_grade);
}

int			AForm::getFormReqGrade(void) const
{
	return(this->_reqGrade);
}

void		AForm::beSigned(Bureaucrat const &Bur)
{
	try
	{
		if (Bur.getGrade() > this->_grade)
		{
			throw AForm::GradeTooLowException();
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

std::ostream& operator<<(std::ostream& os, AForm const& src)
{
	os << "Information for form " << src.getFormName() << std::endl;
	os << "Form's name: " << src.getFormName() << std::endl;
	os << "Is signed?: " << src.getFormSigned() << std::endl;
	os << "Grade required to sign: " << src.getFormGrade() << std::endl;
	os << "Grade required to execute: " << src.getFormReqGrade() << std::endl;
	return (os);
}

void 		AForm::execute(Bureaucrat const & executor) const
{
	try
	{
		if (_signed == false)
		{
			throw AForm::FormNotSigned();
		}
		else if (_reqGrade < executor.getGrade())
		{
			throw AForm::GradeExecuteTooLowException();
		}
		this->executeForm();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
