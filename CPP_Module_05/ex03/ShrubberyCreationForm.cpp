/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 14:22:45 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/22 11:21:15 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("target")
{
	std::cout << "Default ShrubberyCreationForm constructor created." << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destroyed." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor with target equal to " << _target << " created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): AForm(src.getFormName(), src.getFormGrade(), src.getFormReqGrade()), _target(src._target)
{
	std::cout << "ShrubberyCreationForm Copy constructor." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator constructor." << std::endl;
	if (this != &src)
	{
		//this->_target = src._target;
	}
	return (*this);
}

void ShrubberyCreationForm::executeForm(void) const
{
	std::ofstream 	file;
	std::string		filename;
	
	filename = _target + "_shrubbery";
	file.open(filename.c_str(), std::ofstream::out);
	try
	{
		if (!file.is_open())
			throw ShrubberyCreationForm::openFile();
		file <<
		"              * *\n"
		"           *    *  *\n"
		"      *  *    *     *  *\n"
		"     *     *    *  *    *\n"
		" * *   *    *    *    *   *\n"
		" *     *  *    * * .#  *   *\n"
		" *   *     * #.  .# *   *\n"
		"  *     \"#.  #: #\" * *    *\n"
		" *   * * \"#. ##\"       *\n"
		"   *       \"###\n"
		"             \"##\n"
		"              ##.\n"
		"              .##:\n"
		"              :###\n"
		"              ;###\n"
		"            ,####.\n"
		"/\\/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\\n";
		file.close();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
