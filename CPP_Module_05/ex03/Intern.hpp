/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 12:02:19 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/22 13:27:10 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"

class AForm;

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(Intern const &src);
		Intern &operator=(Intern const &src);

		AForm *makeForm(const std::string &nameForm, const std::string &target);
		AForm *PresidentialPardon(const std::string &target);
		AForm *RobotomyRequest(const std::string &target);
		AForm *ShrubberyCreation(const std::string &target);

	class ListFormExeception: public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Cannot find this Form!";
			}
	};
};

#endif
