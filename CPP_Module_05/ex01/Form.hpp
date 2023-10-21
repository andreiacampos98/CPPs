/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaraujo <anaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 20:36:58 by anaraujo          #+#    #+#             */
/*   Updated: 2023/10/21 11:43:55 by anaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const 	_name;
		bool 				_signed;
		int const			_grade;
		int const			_reqGrade;
	public:
		Form();
		~Form();
		Form(const std::string name, int grade, int reqGrade);
		Form(Form const &src);
		Form &operator=(Form const &src);
		
		std::string getFormName(void) const;
		bool		getFormSigned(void) const;
		int			getFormGrade(void) const;
		int			getFormReqGrade(void) const;

		void		beSigned(Bureaucrat const &Bur);

		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Form error - Grade too high";
				}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return "Form error - Grade too low";
				}
		};
};

std::ostream& operator<<(std::ostream& os, Form const& src);

#endif
