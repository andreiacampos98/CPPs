/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:44:25 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/18 23:17:10 by anaraujo         ###   ########.fr       */
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
			std::cout << "Grade too high" << std::endl;
		if (grade > 150)
			std::cout << "Grade too low" << std::endl;
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
	if (this->_grade > 1 && this->_grade <= 150)
		this->_grade--;
}
void Bureaucrat::decrementGrade(Bureaucrat bur)
{
	if (this->_grade >= 1 && this->_grade < 150)
		this->_grade++;
}