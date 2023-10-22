/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:02:22 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/22 14:03:26 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern constructor created." << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed." << std::endl;
}


Intern::Intern(Intern const &src)
{
	*this = src;
	std::cout << "Intern Copy constructor." << std::endl;
}

Intern &Intern::operator=(Intern const &src)
{
	std::cout << "Intern Copy assignment operator constructor." << std::endl;
	if (this != &src)
	{
		return (*this);
	}
	return (*this);
}

AForm *Intern::PresidentialPardon(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::RobotomyRequest(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::ShrubberyCreation(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(const std::string &nameForm, const std::string &target)
{
	AForm		*(Intern::*ptr_form[3])(const std::string&) = {&Intern::PresidentialPardon, &Intern::RobotomyRequest, &Intern::ShrubberyCreation};
	std::string	forms[3] = {"Presidential Pardon", "Robotomy Request", "Shrubbery Creation"};

	for (int i = 0; i < 3; i++)
	{
		if (forms[i] == nameForm)
		{
			return (this->*ptr_form[i])(target);
		}
	}
	throw Intern::ListFormExeception();
}
